// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
int x = 1;
int recursion(vector<int> v, int n, int i, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] == 1)
        return dp[i];
    for (int j = i - 1; j >= 0; j--)
    {
        if (v[i] > v[j])
        {
            dp[i] = max(dp[i], 1 + recursion(v, n, j, dp));
        }
    }
    return dp[i];
}
// O(NlogN)
int shortest(vector<int> v)
{
    int n = v.size();
    vector<int> dp;
    dp.push_back(v[0]);
    int j = 0;
    cout<<v[0]<<" ";
    for (int i = 1; i < n; i++)
    {
        if (v[i] > dp[j])
        {
            dp.push_back(v[i]);
            cout<<v[i]<<" ";
            j++;
        }
        else
        {
            int index = lower_bound(dp.begin(), dp.begin() + j, v[i]) - dp.begin();
            dp[index] = v[i];
        }
    }
    return dp.size();
}
int solve(vector<int> v)
{
    int n = v.size(), ans = 0;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v{3, 2, 4, 1, 7, 8, 6, 10, 9};
    int n = v.size();
    cout << solve(v) << endl;
    vector<int> dp(n + 1, 1);
    // cout << recursion(v, n, 1, dp);
    shortest(v);
    return 0;
}