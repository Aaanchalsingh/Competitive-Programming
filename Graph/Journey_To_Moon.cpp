#include <bits/stdc++.h>

using namespace std;

int dfs_size(int i, vector<int> adj[], vector<bool> &vis)
{
    vis[i] = true;
    int size = 1;
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            int z = dfs_size(x, adj, vis);
            size += z;
        }
    }
    return size;
}
int journeyToMoon(int n, vector<vector<int>> v)
{
    vector<int> adj[n + 1];
    int result = (n * (n - 1));
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < v.size(); i++)
    {
        int cur = v[i][0];
        for (int j = 0; j < v[i].size(); j++)
        {
            adj[cur].push_back(v[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        if (!vis[i])
        {
            int k = dfs_size(i, adj, vis);
            result -= (k * (k - 1)) / 2;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> v{{0, 1}, {2, 3}, {0, 4}};
    cout << journeyToMoon(5, v) << endl;
}
