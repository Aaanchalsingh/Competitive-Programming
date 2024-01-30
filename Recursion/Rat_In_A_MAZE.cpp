#include <bits/stdc++.h>
using namespace std;

//FORMULA

int dfs(int i, int j, vector<vector<int>> &board, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }
    if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0)
        return 0;

    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int ans = 0;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        board[i][j] = 0;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] != 0)
            ans += dfs(ni, nj, board, n);
        board[i][j] = 1;
    }
    return ans;
}
int solve(vector<vector<int>> &board)
{
    int n = board.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = board[i][0];
        dp[0][i] = board[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 1)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n - 1][n - 1];
}

int main()
{
    vector<vector<int>> board{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int ans = 0;
    int n = board.size();
    // cout << dfs(0, 0, board, n);
    cout << solve(board);
    return 0;
}
