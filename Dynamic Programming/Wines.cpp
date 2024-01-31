#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &v, int year)
{
    if (i > j || i >= v.size() || j < 0)
        return 0;
    int takefirst = solve(i + 1, j, v, year + 1) + year * v[i];
    int takesecond = solve(i, j - 1, v, year + 1) + year * v[j];
    return max(takefirst, takesecond);
}
int memo(int i, int j, vector<int> &v, int year, vector<vector<int>> &dp)
{
    if (i > j || i >= v.size() || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int takefirst = memo(i + 1, j, v, year + 1, dp) + year * v[i];
    int takesecond = memo(i, j - 1, v, year + 1, dp) + year * v[j];
    return dp[i][j] = max(takefirst, takesecond);
}
int tabulation(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = v[i] * n;
    }
    int year = n - 1;
    for (int k = 1; k < n; k++)
    {
        for (int j = k; j < n; j++)
        {
            int i = j - k;
            int takefirst = v[i] * year + dp[i + 1][j];
            int takesecond = v[j] * year + dp[i][j - 1];
            dp[i][j] = max(takefirst, takesecond);
        }
        year--;
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> v{2, 3, 5, 1, 4};
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(0, n - 1, v, 1) << endl;
    cout << memo(0, n - 1, v, 1, dp) << endl;
    cout << tabulation(v);
    return 0;
}
