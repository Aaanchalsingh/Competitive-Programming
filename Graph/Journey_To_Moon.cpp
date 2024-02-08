#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<int> adj[], vector<bool> &vis, int &size)
{
    vis[i] = true;
    size++;
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis, size);
        }
    }
}

long long journeyToMoon(int n, vector<vector<int>> &v)
{
    vector<int> adj[n];
    for (auto &edge : v)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(n, false);
    int result = (n * (n - 1)) / 2;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int size = 0;
            dfs(i, adj, vis, size);
            result -= (size * (size - 1)) / 2;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> v{{0, 1}, {2, 3}, {0, 4}};
    cout << journeyToMoon(5, v) << endl;
}
