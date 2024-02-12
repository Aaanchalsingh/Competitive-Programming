#include <iostream>
#include <vector>
using namespace std;

long long solve(int faces, int dice, int target, vector<vector<long long>> &dp)
{
    if (target < 0)
        return 0;
    if (dice == 0 && target != 0)
        return 0;
    if (dice != 0 && target == 0)
        return 0;
    if (dice == 0 && target == 0)
        return 1;

    if (dp[dice][target] != -1)
        return dp[dice][target];
    long long ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans += solve(faces, dice - 1, target - i, dp);
    }
    return dp[dice][target] = ans;
}

long long noOfWays(int m, int n, int target)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    return solve(m, n, target, dp);
}

int main()
{
    int faces = 6;   // Example: 6 faces on each die
    int dice = 3;    // Example: 3 dice
    int target = 10; // Example: Target sum is 10

    long long ways = noOfWays(faces, dice, target);
    cout << "Number of ways to get the target sum: " << ways << endl;

    return 0;
}
