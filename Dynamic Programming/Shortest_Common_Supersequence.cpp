#include <bits/stdc++.h>
using namespace std;

// Shortest Common Subsequence = m+n-LCS

// Obtaining LCS Bottom up
void lcs(string x, string y, int m, int n, vector<vector<int>> &dp){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

// Recursion LCS
int solve_recurrence(string x, string y, int m, int n)
{
    if (m <= 0 || n <= 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + solve_recurrence(x, y, m - 1, n - 1);
    else
       return max(solve_recurrence(x, y, m, n - 1), solve_recurrence(x, y, m - 1, n));
}

// Printing LCS
void Print_LCS(string x, string y, int m, int n, vector<vector<int>> &dp)
{

    int i = m, j = n;
    string ans;
    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    cout << "Longest Common Subsequence: " << ans << endl;
}

// Printing Shortest common Subsequence
void shortestCommonSupersequence(string x, string y, int m, int n, vector<vector<int>> &dp)
{
    lcs(x, y, m, n, dp);
    int i = m, j = n;
    string ans;
    while (i > 0 and j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
        }
        else
        {
            ans.push_back(y[j - 1]);
            j--;
        }
    }
    while (i >= 1)
    {
        ans.push_back(x[--i]);
    }
    while (j >= 1)
    {
        ans.push_back(y[--j]);
    }
    reverse(ans.begin(), ans.end());
    cout << "Shortest Common Supersequence: " << ans << endl;
}

int main()
{
    string x = "ABCD";
    string y = "XYCD";
    int m = x.length();
    int n = y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    cout << solve_recurrence(x, y, m, n) << endl;
    Print_LCS(x, y, m, n, dp);
    shortestCommonSupersequence(x, y, m, n, dp);

    return 0;
}
