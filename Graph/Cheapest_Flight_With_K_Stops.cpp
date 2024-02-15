// BELLMANN FORD ALGORITHM VARIANT
#include <iostream>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<int>> dp(K + 2, vector<int>(n, 1e9));
    for (int i = 0; i <= K + 1; i++)
        dp[i][src] = 0;
    for (int i = 1; i <= K + 1; i++)
    {
        for (auto f : flights)
        {
            int u = f[0];
            int v = f[1];
            int w = f[2];
            if (dp[i - 1][u] != 1e9 && dp[i - 1][u] + w < dp[i][v])
                dp[i][v] = dp[i - 1][u] + w;
        }
    }
    return (dp[K + 1][dst] == 1e9) ? -1 : dp[K + 1][dst];
}

int main()
{
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int K = 1;
    cout << findCheapestPrice(n, flights, src, dst, K) << endl;
    return 0;
}
