// TOTAL NUMBER OF BST WITH N NODES
// WITHOUT USING CATALAN NUMBER 2NCN/N+1
#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    int ans = 0;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        int left = f(i - 1);  // Left BST
        int right = f(n - i); // Right BST
        ans += left * right;
    }
    return ans;
    // Time Complexity = (N)^N
}
int memo(int n, vector<int> &dp)
{
    int ans = 0;
    if (dp[n] != -1)
        return dp[n];
    if (n == 0 || n == 1)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        int left = memo(i - 1, dp);  // Left BST
        int right = memo(n - i, dp); // Right BST
        ans += left * right;
        dp[i] = ans;
    }
    return ans;
    // Time Complexity = (N)^2
}
int tabulated(int n)
{
    vector<int> dp(n + 1, 1);
    int ans = 0;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= i; j++)
        {
            int left = dp[j - 1];
            int right = dp[n - j];
            ans += left * right;
        }
        dp[i] = ans;
    }
    return dp[n];
}
// Time Complexity = (N)^2
int main()
{
    int n = 3;
    cout << f(n) << endl;
    vector<int> dp(n + 1, -1);
    cout << memo(n, dp) << endl;
    cout << tabulated(n) << endl;
    return 0;
}