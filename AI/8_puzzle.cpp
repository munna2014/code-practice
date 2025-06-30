#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;

const vector<vector<int>> TARGET_BOARD = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

const int rowDir[] = {-1, 1, 0, 0};
const int colDir[] = {0, 0, -1, 1};

// Helper Functions
bool isGoalState(const vector<vector<int>>& board) {
    return board == TARGET_BOARD;
}

string boardToString(const vector<vector<int>>& board) {
    string result;
    for (const auto& row : board)
        for (int num : row)
            result += to_string(num);
    return result;
}

bool isValidMove(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// BFS Solver
void bfsSolver(vector<vector<int>> initialBoard, int emptyX, int emptyY) {
    struct PuzzleNode {
        vector<vector<int>> board;
        int emptyX, emptyY, depth;
        string movePath;
    };

    queue<PuzzleNode> q;
    set<string> visited;

    q.push({initialBoard, emptyX, emptyY, 0, ""});
    visited.insert(boardToString(initialBoard));

    while (!q.empty()) {
        PuzzleNode current = q.front();
        q.pop();

        if (isGoalState(current.board)) {
            cout << "BFS Solution found at depth " << current.depth << endl;
            cout << "Move sequence: " << current.movePath << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.emptyX + rowDir[i];
            int newY = current.emptyY + colDir[i];

            if (isValidMove(newX, newY)) {
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[current.emptyX][current.emptyY], newBoard[newX][newY]);

                string newBoardStr = boardToString(newBoard);
                if (visited.find(newBoardStr) == visited.end()) {
                    visited.insert(newBoardStr);
                    q.push({newBoard, newX, newY, current.depth + 1, current.movePath + "URDL"[i]});
                }
            }
        }
    }
    cout << "No solution found using BFS!" << endl;
}

bool dfsSolver(vector<vector<int>> board, int depth, int maxDepth, unordered_set<string> &visited,
               int emptyX, int emptyY, string movePath)
{
    if (isGoalState(board))
    {
        cout << "DFS Solution found at depth " << depth << endl;
        cout << "Move sequence: " << movePath << endl;
        return true;
    }
    if (depth >= maxDepth)
    {
        return false;
    }

    string boardStr = boardToString(board);
    visited.insert(boardStr);

    for (int i = 0; i < 4; i++)
    {
        int newX = emptyX + rowDir[i];
        int newY = emptyY + colDir[i];

        if (isValidMove(newX, newY))
        {
            swap(board[emptyX][emptyY], board[newX][newY]);
            boardStr = boardToString(board);

            if (visited.find(boardStr) == visited.end())
            {
                string newMovePath = movePath + "URDL"[i]; // Add the current move to the path
                if (dfsSolver(board, depth + 1, maxDepth, visited, newX, newY, newMovePath))
                {
                    return true;
                }
            }
            swap(board[emptyX][emptyY], board[newX][newY]);
        }
    }
    visited.erase(boardStr);
    return false;
}

// Main Function
int main() {
    vector<vector<int>> initialBoard = {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}
    };

    int emptyX = 1, emptyY = 1; // Position of the empty tile
    int choice;

    cout << "Choose search method:\n1. BFS\n2. DFS\n";
    cin >> choice;

    if (choice == 2)
    {
        int maxDepthLimit = 50;
        unordered_set<string> visitedNodes;
        if (!dfsSolver(initialBoard, 0, maxDepthLimit, visitedNodes, emptyX, emptyY, ""))
        {
            cout << "No solution found using DFS within depth " << maxDepthLimit << endl;
        }
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
