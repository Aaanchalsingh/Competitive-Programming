/*
DUTY DISTRIBUTION
MINIMUM ELEMENT IN A SLIDING WINDOW IF REPEATED DONT COUNT THE SAME INDEX AGAIN IN A SLIDING WINDOW
LIKE 3,2,1,1,2,3,1,3,2,1 here if output = 4
*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v, int n)
{
    int mini = 1e9, k = 1e9;
    vector<int> dp(n + 1, 0);
    dp[0] = v[0];
    dp[1] = v[1];
    dp[2] = v[2];
    for (int i = 3; i < n; i++)
    {
        mini = 1e9;
        for (int j = i - 1; j >= i - 3; j--)
        {
            mini = min(mini, dp[j]);
        }
        dp[i] = v[i] + mini;
    }
    for (int i = n - 3; i < n; i++)
        k = min(k, dp[i]);
    return k;
}
int main()
{
    vector<int> v{3, 2, 1, 1, 2, 3, 1, 3, 2, 1};
    int n = v.size();
    cout << solve(v, n);
    return 0;
}