// EDIT DISTANCE {TRANSFORM S1 INTO S2 {INSERT,DELETE,REPLACE}}
#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y, int m, int n, vector<vector<int>> &dp)
{
    if (m < 0 and n < 0)
        return 0;
    if (m <= 0 or n <= 0)
    {
        return abs(m - n);
    }
    if (dp[m][n] != -1)
        return dp[m][n];
    if (x[m - 1] == y[n - 1])
        return dp[m][n] = solve(x, y, m - 1, n - 1, dp);
    return dp[m][n] = min({1 + solve(x, y, m - 1, n, dp),
                           1 + solve(x, y, m, n - 1, dp),
                           1 + solve(x, y, m - 1, n - 1, dp)});
}
int minDistance(string w1, string w2)
{
    int m = w1.size(), n = w2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (w1[i - 1] == w2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] =
                    1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[m][n];
}
int main()
{
    string word1 = "kitten";
    string word2 = "sitting";
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << solve(word1, word2, word1.size(), word2.size(), dp) << endl;
    cout << minDistance(word1, word2) << endl;
    return 0;
}