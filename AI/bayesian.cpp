#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Bayesian Node Structure
struct BayesianNode
{
    string name;
    vector<string> parents;
    vector<vector<double>> cpd;
};

// Forward declaration for query function
double computeProbability(const map<string, int> &evidence, const vector<BayesianNode> &nodes, const string &targetNode, int targetValue);

// Compute joint probability
double jointProbability(const map<string, int> &evidence, const vector<BayesianNode> &nodes)
{
    double probability = 1.0;

    for (const auto &node : nodes)
    {
        // Ensure the node exists in the evidence map
        if (evidence.find(node.name) == evidence.end())
        {
            cerr << "Error: Missing value for node '" << node.name << "' in evidence." << endl;
            return 0.0; // Return an invalid probability
        }

        int value = evidence.at(node.name);
        vector<string> parents = node.parents;

        // Get parent values
        int index = 0;
        if (!parents.empty())
        {
            int multiplier = 1;
            for (const auto &parent : parents)
            {
                if (evidence.find(parent) == evidence.end())
                {
                    cerr << "Error: Missing parent '" << parent << "' for node '" << node.name << "' in evidence." << endl;
                    return 0.0; // Return an invalid probability
                }
                index += multiplier * evidence.at(parent);
                multiplier *= 2;
            }
        }

        // Update probability
        probability *= node.cpd[value][index];
    }

    return probability;
}

// Marginalize over target node
double computeProbability(const map<string, int> &evidence, const vector<BayesianNode> &nodes, const string &targetNode, int targetValue)
{
    map<string, int> updatedEvidence = evidence;
    updatedEvidence[targetNode] = targetValue;

    return jointProbability(updatedEvidence, nodes);
}

// Main
int main()
{
    // Define Bayesian Nodes
    BayesianNode B = {"B", {}, {{0.999}, {0.001}}};
    BayesianNode E = {"E", {}, {{0.998}, {0.002}}};
    BayesianNode A = {"A", {"B", "E"}, {{0.999, 0.71, 0.06, 0.05}, {0.001, 0.29, 0.94, 0.95}}};
    BayesianNode J = {"J", {"A"}, {{0.1, 0.95}, {0.9, 0.05}}};
    BayesianNode M = {"M", {"A"}, {{0.3, 0.99}, {0.7, 0.01}}};

    vector<BayesianNode> nodes = {B, E, A, J, M};

    // Define evidence: J = 1, M = 1
    map<string, int> evidence = {{"J", 1}, {"M", 1}, {"B", 0}, {"E", 0}, {"A", 1}};

    // Compute probabilities for B
    double probB0 = computeProbability(evidence, nodes, "B", 0);
    double probB1 = computeProbability(evidence, nodes, "B", 1);

    // Normalize results
    double totalProb = probB0 + probB1;
    if (totalProb > 0)
    {
        probB0 /= totalProb;
        probB1 /= totalProb;
    }
    else
    {
        cerr << "Error: Total probability is zero. Check your inputs." << endl;
        return 1;
    }

    // Output results
    cout << "P(B=0 | J=1, M=1): " << probB0 << endl;
    cout << "P(B=1 | J=1, M=1): " << probB1 << endl;

    return 0;
}
