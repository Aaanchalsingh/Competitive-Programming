// RAT IN A MAZE WITH HURDLES
// WE CANNOT PRINT USING DP METHOD
// SINCE IT WILL ONLY GIVE ONE PATH

#include <bits/stdc++.h>
using namespace std;
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
    cout << solve(board);
    return 0;
}
