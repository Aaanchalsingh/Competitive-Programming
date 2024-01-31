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
int bottom_up(vector<int> v)
{
    int n = v.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int take = dp[i - 1] + abs(v[i - 1] - v[i - 2]);
        int nottake = 100;
        if (i - 3 < v.size())
            nottake = dp[i - 2] + abs(v[i - 1] - v[i - 3]);
        dp[i] = min(take, nottake);
    }
    return dp[n-1];
}
int main()
{
    vector<int> v{10, 20, 30, 10};
    cout << solve(v, v.size() - 1) << endl;
    cout << bottom_up(v);

    return 0;
}