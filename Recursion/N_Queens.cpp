// N QUEENS
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    // FOR CHECKING IN ALL DIRECTION ROW,COLUMN,DIAGNOL AND ANTI-DIAGONALLINE NO QUEEN EXIST
    int i = 0, j = 0;
    // WE NEED TO ONLY CHECK THE LEFT HANDSIDE
    // ROW
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }
    // DIAGNOL
    i = row - 1;
    j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }
    // ANTI DIAGONAL
    i = row + 1;
    j = col - 1;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true;
}
void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
}
void solve(vector<vector<int>> &board, int i, int n)
{
    if (i == n)
    {
        print(board);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            solve(board, i + 1, n);
            board[i][j] = 0;
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, 0, n);
    return 0;
}