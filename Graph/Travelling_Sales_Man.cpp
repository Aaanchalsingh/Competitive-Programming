#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> dist, int n, int city, int visited, vector<vector<int>> &dp)
{
    if (visited == (1 << n) - 1)
    {
        return dist[city][0]; // go to start point
    }
    if (dp[city][visited] != -1)
        return dp[city][visited];

    int ans = 1e9, k = 0;
    for (int i = 0; i < n; i++)
    {
        if ((visited & (1 << i)) == 0)
        {
            k = dist[city][i] + tsp(dist, n, i, (visited | (1 << i)), dp);
            ans = min(ans, k);
        }
    }
    return dp[city][visited] = ans;
}

int main()
{

    vector<vector<int>> dist{
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}};
    int n = dist.size();
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    cout << tsp(dist, n, 0, 1, dp) << endl;

    return 0;
}