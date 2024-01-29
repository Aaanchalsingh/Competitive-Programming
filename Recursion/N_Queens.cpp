// N QUEENS
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &board, int i, int j, int n)
{
}
void print(vector<vector<int>> &board)
{
}
bool solve(vector<vector<int>> &board, int i, int n)
{
    if (i == n)
    {
        print(board);
        return true;
    }
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
        }
    }
    bool safe = solve(board, i + 1, n);
    if (safe)
        return true;
    else
        solve(board, i + 1, n);
    return false;
}
int main()
{
    int n = 4;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    solve(board, 0, n);
    return 0;
}