// INDIAN COIN CHANGE
// REACH A TARGET WITH MINIMUM NO. OF COINS
#include <bits/stdc++.h>
using namespace std;
int Greedy(vector<int> v, int target)
{
    vector<int>::iterator it = upper_bound(v.begin(), v.end(), target);
    int val = it - v.begin();
    int coins = 0, i = val - 1;
    while (target > 0 && i >= 0)
    {
        if (v[i] <= target)
        {
            coins++;
            target -= v[i];
        }
        else
            i--;
    }
    return coins;
}
int DP_Brute(vector<int> v, int target, int i)
{
    if (i == 0)
    {
        if (target % v[i] == 0)
            return target / v[i];
        else
            return 1e9;
    }
    if (target <= 0)
        return 1e9;
    int nottake = DP_Brute(v, target, i - 1);
    int take = 1e9;
    if (target - v[i] >= 0)
        take = 1 + DP_Brute(v, target - v[i], i);
    return min(take, nottake);
}
int DP_Memoized(vector<int> v, int target, int i, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (target % v[i] == 0)
            return target / v[i];
        else
            return 1e9;
    }
    if (dp[i][target] != -1)
        return dp[i][target];
    int nottake = DP_Memoized(v, target, i - 1, dp);
    int take = 1e9;
    if (target - v[i] >= 0)
        take = 1 + DP_Memoized(v, target - v[i], i, dp);
    dp[i][target] = min(take, nottake);
}
int DP_Tabulation(vector<int> v, int target, int i, vector<vector<int>> &dp)
{
}
int main()
{
    vector<int> v{1, 2, 5, 10, 20, 50, 100, 200, 500};
    int target = 458;
    cout << Greedy(v, target) << endl;
    cout << DP_Brute(v, target, v.size() - 1) << endl;
    vector<vector<int>> dp(v.size() + 1, vector<int>(target + 1, -1));
    cout << DP_Memoized(v, target, v.size() - 1, dp) << endl;
    cout << DP_Tabulation(v, target, v.size() - 1, dp) << endl;
    return 0;
}