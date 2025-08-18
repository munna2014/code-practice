#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <tuple>

using namespace std;

struct Node
{
    int row, col;
    int gCost, hCost;
    Node *parent;

    Node(int r, int c, int g, int h, Node *p = nullptr)
        : row(r), col(c), gCost(g), hCost(h), parent(p) {}

    int fCost() const
    {
        return gCost + hCost;
    }

    // For priority queue
    bool operator>(const Node &other) const
    {
        return fCost() > other.fCost();
    }
};

int heuristic(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2); // Manhattan distance
}

bool isValid(int row, int col, const vector<vector<int>> &grid)
{
    return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 0;
}

void printPath(Node *end)
{
    stack<pair<int, int>> path;
    int cost = 0;
    while (end)
    {
        path.push({end->row, end->col});
        end = end->parent;
        cost++;
    }

    cout << "Shortest path:\n";
    while (!path.empty())
    {
        auto [r, c] = path.top();
        path.pop();
        cout << "(" << r << "," << c << ") ";
    }
    cout << "\nTotal cost: " << cost - 1 << endl;
}

void aStarSearch(const vector<vector<int>> &grid, int stR, int stC, int glR, int glC)
{
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    openSet.emplace(stR, stC, 0, heuristic(stR, stC, glR, glC));

    while (!openSet.empty())
    {
        Node current = openSet.top();
        openSet.pop();

        if (visited[current.row][current.col])
            continue;
        visited[current.row][current.col] = true;

        if (current.row == glR && current.col == glC)
        {
            printPath(&current);
            return;
        }

                const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (isValid(newRow, newCol, grid) && !visited[newRow][newCol])
            {
                int g = current.gCost + 1;
                int h = heuristic(newRow, newCol, glR, glC);
                openSet.emplace(newRow, newCol, g, h, new Node(current));
            }
        }
    }

    cout << "No path found.\n";
}

int main()
{
    int rows, cols;
    cout << "Enter grid size (rows cols): ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter grid (0 for free, 1 for obstacle):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];

    int stR, stC, glR, glC;
    cout << "Enter start position (row col): ";
    cin >> stR >> stC;
    cout << "Enter goal position (row col): ";
    cin >> glR >> glC;

    if (!isValid(stR, stC, grid) || !isValid(glR, glC, grid))
    {
        cout << "Invalid start or goal position.\n";
        return 1;
    }

    aStarSearch(grid, stR, stC, glR, glC);

    return 0;
}
