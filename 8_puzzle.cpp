// Using BFS:
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int rowDir[] = {1, -1, 0, 0};
int colDir[] = {0, 0, -1, 1};                                                                                                      

struct PuzzleNode
{
    vector<vector<int>> board;
    int emptyX, emptyY, depth;
    string movePath;
};

bool isGoalState(const vector<vector<int>> &board)
{
    vector<vector<int>> goalBoard = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    return board == goalBoard;
}

string boardToString(const vector<vector<int>> &board)
{
    string result = "";
    for (auto &row : board)
        for (auto &num : row)
            result += to_string(num);
    return result;
}

bool isValidMove(int x, int y)
{
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

void bfsSolver(vector<vector<int>> initialBoard, int emptyX, int emptyY)
{
    queue<PuzzleNode> q;
    set<string> visited;

    PuzzleNode root = {initialBoard, emptyX, emptyY, 0, ""};
    q.push(root);
    visited.insert(boardToString(initialBoard));

    while (!q.empty())
    {
        PuzzleNode current = q.front();
        q.pop();

        if (isGoalState(current.board))
        {
            cout << "Solution found at depth " << current.depth << endl;
            cout << "Move sequence: " << current.movePath << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = current.emptyX + rowDir[i];
            int newY = current.emptyY + colDir[i];

            if (isValidMove(newX, newY))
            {
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[current.emptyX][current.emptyY], newBoard[newX][newY]);

                string newBoardStr = boardToString(newBoard);
                if (visited.find(newBoardStr) == visited.end())
                {
                    visited.insert(newBoardStr);
                    q.push({newBoard, newX, newY, current.depth + 1, current.movePath + "URDL"[i]});
                }
            }
        }
    }
    cout << "No solution found!" << endl;
}

int main()
{
    vector<vector<int>> initialBoard = {{1, 2, 3}, {4, 0, 5}, {6, 7, 8}};
    int emptyX = 1, emptyY = 1; // Position of zero
    bfsSolver(initialBoard, emptyX, emptyY);
    return 0;
}
