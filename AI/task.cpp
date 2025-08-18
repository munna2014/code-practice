#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

struct Individual
{
    vector<int> assignment; // task to worker mapping
    int makespan;
};

int calculateMakespan(const vector<int> &assignment, const vector<int> &taskTimes, int numWorkers)
{
    vector<int> workerTimes(numWorkers, 0);
    for (int i = 0; i < assignment.size(); i++)
    {
        workerTimes[assignment[i]] += taskTimes[i];
    }
    return *max_element(workerTimes.begin(), workerTimes.end());
}

Individual generateIndividual(int numTasks, int numWorkers, const vector<int> &taskTimes, mt19937 &rng)
{
    Individual ind;
    ind.assignment.resize(numTasks);
    for (int i = 0; i < numTasks; i++)
    {
        ind.assignment[i] = rng() % numWorkers;
    }
    ind.makespan = calculateMakespan(ind.assignment, taskTimes, numWorkers);
    return ind;
}

void mutate(Individual &ind, int numWorkers, mt19937 &rng)
{
    uniform_int_distribution<int> dist(0, ind.assignment.size() - 1);
    int idx = dist(rng);
    ind.assignment[idx] = rng() % numWorkers;
}

Individual crossover(const Individual &parent1, const Individual &parent2, const vector<int> &taskTimes, int numWorkers, mt19937 &rng)
{
    int numTasks = parent1.assignment.size();
    Individual child;
    child.assignment.resize(numTasks);

    for (int i = 0; i < numTasks; i++)
    {
        child.assignment[i] = (rng() % 2 == 0) ? parent1.assignment[i] : parent2.assignment[i];
    }
    child.makespan = calculateMakespan(child.assignment, taskTimes, numWorkers);
    return child;
}

Individual geneticAlgorithm(const vector<int> &taskTimes, int numWorkers, int generations = 500, int populationSize = 100)
{
    int numTasks = taskTimes.size();
    mt19937 rng(time(0));
    vector<Individual> population;

    // Initial population
    for (int i = 0; i < populationSize; i++)
    {
        population.push_back(generateIndividual(numTasks, numWorkers, taskTimes, rng));
    }

    Individual best = population[0];

    for (int gen = 0; gen < generations; gen++)
    {
        sort(population.begin(), population.end(), [](const Individual &a, const Individual &b)
             { return a.makespan < b.makespan; });

        if (population[0].makespan < best.makespan)
        {
            best = population[0];
        }

        vector<Individual> newPopulation;

        // Elitism: keep top 10%
        int eliteSize = populationSize * 0.1;
        for (int i = 0; i < eliteSize; i++)
        {
            newPopulation.push_back(population[i]);
        }

        // Generate rest of the population
        while (newPopulation.size() < populationSize)
        {
            int idx1 = rng() % (populationSize / 2);
            int idx2 = rng() % (populationSize / 2);
            Individual child = crossover(population[idx1], population[idx2], taskTimes, numWorkers, rng);

            if (rng() % 100 < 20)
            { // 20% mutation rate
                mutate(child, numWorkers, rng);
                child.makespan = calculateMakespan(child.assignment, taskTimes, numWorkers);
            }

            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    return best;
}

void printSolution(const Individual &solution, const vector<int> &taskTimes, int numWorkers)
{
    vector<vector<int>> workerTasks(numWorkers);
    vector<int> workerTimes(numWorkers, 0);

    for (int i = 0; i < solution.assignment.size(); i++)
    {
        int worker = solution.assignment[i];
        workerTasks[worker].push_back(i);
        workerTimes[worker] += taskTimes[i];
    }

    for (int i = 0; i < numWorkers; i++)
    {
        cout << "Worker " << i + 1 << ": ";
        for (int task : workerTasks[i])
        {
            cout << "Task " << task << "(" << taskTimes[task] << ") ";
        }
        cout << endl;
    }

    cout << "Makespan: " << solution.makespan << endl;
}

int main()
{
    int numTasks, numWorkers;
    cout << "Enter number of tasks: ";
    cin >> numTasks;

    vector<int> taskTimes(numTasks);
    cout << "Enter execution times: ";
    for (int i = 0; i < numTasks; i++)
    {
        cin >> taskTimes[i];
    }

    cout << "Enter number of workers: ";
    cin >> numWorkers;

    Individual bestSolution = geneticAlgorithm(taskTimes, numWorkers);

    printSolution(bestSolution, taskTimes, numWorkers);

    return 0;
}

