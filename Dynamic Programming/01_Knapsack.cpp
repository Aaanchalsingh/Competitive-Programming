// 01 KNAPSACK {Bounded Supply}
// For 01 Knapsack with infinite supply {Unbounded} just change
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> wt, vector<int> cost, int capacity, int i)
{
    if (capacity == 0 || i < 0)
        return 0;
    int nottake = solve(wt, cost, capacity, i - 1);
    int take = 0;
    if (capacity - wt[i] >= 0)
        take = solve(wt, cost, capacity - wt[i], i - 1) + cost[i];
    // here to i for infinite supply
    return max(take, nottake);
}
int memo(vector<int> wt, vector<int> cost, int capacity, int i, vector<vector<int>> &dp)
{
    if (capacity == 0 || i < 0)
        return 0;
    if (dp[i][capacity] != -1)
        return dp[i][capacity];
    int nottake = memo(wt, cost, capacity, i - 1, dp);
    int take = 0;
    if (capacity - wt[i] >= 0)
        take = memo(wt, cost, capacity - wt[i], i - 1, dp) + cost[i];
    return dp[i][capacity] = max(take, nottake);
}
int bottom_up(vector<int> wt, vector<int> cost, int cap)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int capacity = 1; capacity <= cap; capacity++)
        {
            int nottake = dp[i - 1][capacity];
            int take = 0;
            if (capacity - wt[i - 1] >= 0)
                take = dp[i - 1][capacity - wt[i - 1]] + cost[i - 1];
            dp[i][capacity] = max(take, nottake);
        }
    }
    return dp[n][cap];
}
int main()
{
    vector<int> wt{1, 5, 3, 7};
    vector<int> cost{20, 30, 15, 40};
    int n = wt.size();
    int capacity = 10;
    cout << solve(wt, cost, capacity, n - 1) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    cout << memo(wt, cost, capacity, n - 1, dp) << endl;
    cout << bottom_up(wt, cost, capacity) << endl;
    return 0;
}