
#include<bits/stdc++.h>
using namespace std;

// Constants for the game
const char HUMAN = 'O';
const char AI = 'X';
const char EMPTY = '_';

// Function to print the board
void printBoard(vector<vector<char>> &board)
{
    for (auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }
    cout << endl;
}

// Function to check if there are moves left on the board
bool isMovesLeft(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return true;
    return false;
}

// Function to evaluate the board
int evaluate(vector<vector<char>> &board)
{
    // Check rows for a winner
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
        {
            if (board[row][0] == AI)
                return +10;
            else if (board[row][0] == HUMAN)
                return -10;
        }
    }

    // Check columns for a winner
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
        {
            if (board[0][col] == AI)
                return +10;
            else if (board[0][col] == HUMAN)
                return -10;
        }
    }

    // Check diagonals for a winner
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == AI)
            return +10;
        else if (board[0][0] == HUMAN)
            return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == AI)
            return +10;
        else if (board[0][2] == HUMAN)
            return -10;
    }

    // No winner
    return 0;
}

// Min-Max algorithm
int minimax(vector<vector<char>> &board, int depth, bool isMax)
{
    int score = evaluate(board);

    // If AI or Human wins
    if (score == 10)
        return score - depth;
    if (score == -10)
        return score + depth;

    // If no more moves and no winner
    if (!isMovesLeft(board))
        return 0;

    if (isMax)
    {
        int best = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = AI;
                    best = max(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
    else
    {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = HUMAN;
                    best = min(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

// Find the best move for AI
pair<int, int> findBestMove(vector<vector<char>> &board)
{
    int bestVal = INT_MIN;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = AI;
                int moveVal = minimax(board, 0, false);
                board[i][j] = EMPTY;

                if (moveVal > bestVal)
                {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int main()
{
    // Initialize board
    vector<vector<char>> board = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}};

    printBoard(board);

    while (isMovesLeft(board))
    {
        // Human move
        int x, y;
        cout << "Enter your move (row and column): ";
        cin >> x >> y;
        if (board[x][y] != EMPTY)
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[x][y] = HUMAN;

        printBoard(board);

        // Check if the game is over
        if (evaluate(board) == -10)
        {
            cout << "You win!" << endl;
            break;
        }

        if (!isMovesLeft(board))
        {
            cout << "It's a draw!" << endl;
            break;
        }

        // AI move
        pair<int, int> bestMove = findBestMove(board);
        board[bestMove.first][bestMove.second] = AI;

        printBoard(board);

        // Check if the game is over
        if (evaluate(board) == 10)
        {
            cout << "AI wins!" << endl;
            break;
        }
    }

    if (!isMovesLeft(board) && evaluate(board) == 0)
        cout << "It's a draw!" << endl;

    return 0;
}
