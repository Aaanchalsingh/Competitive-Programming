// MINIMUM STEPS TO 1
#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x = 1e9, y = 1e9, z = 1e9;
        if (i % 3 == 0)
            x = dp[i / 3];
        if (i % 2 == 0)
            y = dp[i / 2];
        z = dp[i - 1];
        dp[i] = min({x + 1, y + 1, z + 1});
    }
    return dp[n];
}
int main()
{
    int n = 11;
    cout << solve(n);
    return 0;
}