// FROG JUMP
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v, int i)
{
    if (i == 0)
        return 0;
    int take = solve(v, i - 1) + abs(v[i] - v[i - 1]);
    int nottake = 100;
    if (i - 2 < v.size())
        nottake = solve(v, i - 2) + abs(v[i] - v[i - 2]);
    return min(take, nottake);
}
int memo(vector<int> v, int i, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int take = memo(v, i - 1, dp) + abs(v[i] - v[i - 1]);
    int nottake = 100;
    if (i - 2 < v.size())
        nottake = memo(v, i - 2, dp) + abs(v[i] - v[i - 2]);
    return dp[i] = min(take, nottake);
}
int bottom_up(vector<int> v)
{
    int n = v.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int take = dp[i - 1] + abs(v[i - 1] - v[i - 2]);
        int nottake = 1e9;
        if (i - 3 < v.size())
            nottake = dp[i - 2] + abs(v[i - 1] - v[i - 3]);
        dp[i] = min(take, nottake);
    }
    return dp[n];
}
int main()
{
    vector<int> v{10, 20, 30, 10};
    int n = v.size();
    cout << solve(v, n - 1) << endl;
    vector<int> dp(n + 1, -1);
    cout << memo(v, n - 1, dp) << endl;
    cout << bottom_up(v);
    return 0;
}