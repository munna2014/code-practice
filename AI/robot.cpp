#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;

int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};

struct Node
{
    vector<vector<int>> state;
    int x, y, level, cost;
    string path;

    bool operator>(const Node &other) const
    {
        return (level + cost) > (other.level + other.cost);
    }
};

vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

bool isGoal(const vector<vector<int>> &state)
{
    return state == goal;
}

string stateToString(const vector<vector<int>> &state)
{
    string res = "";
    for (auto &row : state)

        for (auto &val : row)
            res += to_string(val);
    return res;
}

bool isValid(int x, int y)
{
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int calculateManhattan(const vector<vector<int>> &state)
{
    int distance = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != 0)
            {
                int targetX = (state[i][j] - 1) / 3;
                int targetY = (state[i][j] - 1) % 3;
                distance += abs(i - targetX) + abs(j - targetY);
            }
        }
    }
    return distance;
}

void aStar(vector<vector<int>> start, int x, int y)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<string> visited;

    Node root = {start, x, y, 0, calculateManhattan(start), ""};
    pq.push(root);

    visited.insert(stateToString(start));

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (isGoal(current.state))
        {
            cout << "Solution found at level " << current.level << endl;
            cout << "Path: " << current.path << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = current.x + row[i];
            int newY = current.y + col[i];

            if (isValid(newX, newY))
            {
                vector<vector<int>> newState = current.state;
                swap(newState[current.x][current.y], newState[newX][newY]);

                string newStateStr = stateToString(newState);
                if (visited.find(newStateStr) == visited.end())
                {
                    visited.insert(newStateStr);
                    pq.push({newState, newX, newY, current.level + 1, calculateManhattan(newState),
                             current.path + "URDL"[i]});
                }
            }
        }
    }

    cout << "No solution found!" << endl;
}

int main()
{
    vector<vector<int>> start = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    int x = 1, y = 1;

    aStar(start, x, y);
    return 0;
}
//write a program that takes as input 2D grid map of the warehouse(0=free space, 1= obstacle). and then reads the start and goal positions(row,coloumn).now implrment A* algorithm to compute the shortest path from start to goal, avoiding obstacle. finally print the path and total cost.