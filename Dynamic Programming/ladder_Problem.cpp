#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int k, int n){
    if (n == 0)
        return 1;
    int ans = 0;
    for (int i = 1; i <= k && n - i >= 0; i++)
    {
        ans += solve(v, k, n - i);
    }
    return ans;
}
int memo(vector<int> &v, int k, int n, vector<int> &dp)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= k && n - i >= 0; i++)
    {
        ans += memo(v, k, n - i, dp);
    }

    return dp[n] = ans;
}
int tabulation(vector<int> &v, int k, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            dp[i] += dp[i - j];
        }
    }

    return dp[n];
}
int sliding(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < k; i++)
        dp[i] = 2 * v[i];
    for (int i = k; i < n; i++)
        dp[i] = dp[i - k + 1] + 2 * v[i];
    return dp[n];
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    int n = v.size();
    vector<int> dp(n + 1, -1);
    cout << memo(v, k, n, dp) << endl;
    cout << tabulation(v, k, n) << endl;
    cout << sliding(v, k);
    return 0;
}
