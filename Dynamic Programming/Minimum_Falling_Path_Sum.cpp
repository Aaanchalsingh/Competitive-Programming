#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>> &v,
          vector<vector<int>> &dp)
{
    if (j < 0 or j >= n)
        return 1e9;
    if (dp[i][j] != 1e9)
        return dp[i][j];
    if (i == n - 1)
        return dp[i][j] = v[n - 1][j];
    return dp[i][j] = min({solve(i + 1, j - 1, n, v, dp),
                           solve(i + 1, j, n, v, dp),
                           solve(i + 1, j + 1, n, v, dp)}) +
                      v[i][j];
}

int minFallingPathSum(vector<vector<int>> &v)
{
    int n = v.size(), ans = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, solve(0, j, n, v, dp));
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{2, 1, 3},
                                  {6, 5, 4},
                                  {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;
    return 0;
}
