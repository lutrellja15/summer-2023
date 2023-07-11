/****************
Baylee Caldwell
00106404
July 12, 2023
Problem 3
*****************/

#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

void displayBoard(const char board[][BOARD_SIZE]);
void takeTurn(char board[][BOARD_SIZE], char playerSymbol);
bool isGameOver(const char board[][BOARD_SIZE]);
bool hasPlayerWon(const char board[][BOARD_SIZE], char playerSymbol);
bool canPlayerWin(const char board[][BOARD_SIZE], char playerSymbol);
void displayWinner(char playerSymbol);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board with asterisks
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            board[row][col] = '*';
        }
    }

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard(board);
        takeTurn(board, currentPlayer);

        if (hasPlayerWon(board, currentPlayer))
        {
            displayBoard(board);
            displayWinner(currentPlayer);
            gameOver = true;
        }
        else if (canPlayerWin(board, currentPlayer))
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else if (isGameOver(board))
        {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        }
        else
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void displayBoard(const char board[][BOARD_SIZE])
{
    cout << "Current board:" << endl;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void takeTurn(char board[][BOARD_SIZE], char playerSymbol)
{
    int row, col;
    cout << "Player " << playerSymbol << ", enter the row and column numbers (0-2): ";
    cin >> row >> col;

    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '*')
    {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }

    board[row][col] = playerSymbol;
}

bool isGameOver(const char board[][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == '*')
            {
                return false;
            }
        }
    }
    return true;
}

bool hasPlayerWon(const char board[][BOARD_SIZE], char playerSymbol)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][0] == playerSymbol && board[row][1] == playerSymbol && board[row][2] == playerSymbol)
        {
            return true;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (board[0][col] == playerSymbol && board[1][col] == playerSymbol && board[2][col] == playerSymbol)
        {
            return true;
        }
    }

    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
    {
        return true;
    }

    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
    {
        return true;
    }

    return false;
}

bool canPlayerWin(const char board[][BOARD_SIZE], char playerSymbol)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        int count = 0;
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == playerSymbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE - 1)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (board[row][col] == '*')
                {
                    board[row][col] = playerSymbol;
                    return true;
                }
            }
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++)
    {
        int count = 0;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            if (board[row][col] == playerSymbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE - 1)
        {
            for (int row = 0; row < BOARD_SIZE; row++)
            {
                if (board[row][col] == '*')
                {
                    board[row][col] = playerSymbol;
                    return true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][i] == playerSymbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][i] == '*')
            {
                board[i][i] = playerSymbol;
                return true;
            }
        }
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][BOARD_SIZE - 1 - i] == playerSymbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][BOARD_SIZE - 1 - i] == '*')
            {
Apologies for the incomplete code. Here's the complete version:

```cpp
#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;

void displayBoard(const char board[][BOARD_SIZE]);
void takeTurn(char board[][BOARD_SIZE], char playerSymbol);
bool isGameOver(const char board[][BOARD_SIZE]);
bool hasPlayerWon(const char board[][BOARD_SIZE], char playerSymbol);
bool canPlayerWin(const char board[][BOARD_SIZE], char playerSymbol);
void displayWinner(char playerSymbol);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the board with asterisks
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            board[row][col] = '*';
        }
    }

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard(board);
        takeTurn(board, currentPlayer);

        if (hasPlayerWon(board, currentPlayer))
        {
            displayBoard(board);
            displayWinner(currentPlayer);
            gameOver = true;
        }
        else if (isGameOver(board))
        {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        }
        else
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void displayBoard(const char board[][BOARD_SIZE])
{
    cout << "Current board:" << endl;
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << board[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void takeTurn(char board[][BOARD_SIZE], char playerSymbol)
{
    int row, col;
    cout << "Player " << playerSymbol << ", enter the row and column numbers (0-2): ";
    cin >> row >> col;

    while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != '*')
    {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }

    board[row][col] = playerSymbol;
}

bool isGameOver(const char board[][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == '*')
            {
                return false;
            }
        }
    }
    return true;
}

bool hasPlayerWon(const char board[][BOARD_SIZE], char playerSymbol)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][0] == playerSymbol && board[row][1] == playerSymbol && board[row][2] == playerSymbol)
        {
            return true;
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (board[0][col] == playerSymbol && board[1][col] == playerSymbol && board[2][col] == playerSymbol)
        {
            return true;
        }
    }

    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
    {
        return true;
    }

    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
    {
        return true;
    }

    return false;
}

bool canPlayerWin(const char board[][BOARD_SIZE], char playerSymbol)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        int count = 0;
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == playerSymbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE - 1)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (board[row][col] == '*')
                {
                    return true;
                }
            }
        }
    }

    for (int col = 0; col < BOARD_SIZE; col++)
    {
        int count = 0;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            if (board[row][col] == playerSymbol)
            {
                count++;
            }
        }
        if (count == BOARD_SIZE - 1)
        {
            for (int row = 0; row < BOARD_SIZE; row++)
            {
                if (board[row][col] == '*')
                {
                    return true;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][i] == playerSymbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][i] == '*')
            {
                return true;
            }
        }
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][BOARD_SIZE - 1 - i] == playerSymbol)
        {
            count++;
        }
    }
    if (count == BOARD_SIZE - 1)
    {
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][BOARD_SIZE - 1 - i] == '*')
            {
                return true;
            }
        }
    }

    return false;
}

void displayWinner(char playerSymbol)
{
    cout << "Player " << playerSymbol << " wins!" << endl;
}
