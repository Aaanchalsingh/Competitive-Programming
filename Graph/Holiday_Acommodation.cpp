#include <bits/stdc++.h>
using namespace std;
int ans = 0;

void dfs(int i, vector<vector<pair<int, int>>> adj, vector<bool> &vis, vector<int> &ans)
{
    vis[i] = true;
    ans.push_back(i);
    for (auto x : adj[i])
    {
        if (!vis[x.first])
        {
            dfs(x.first, adj, vis, ans);
        }
    }
}
int solve(int i, vector<vector<pair<int, int>>> graph, int n)
{
    vector<bool> vis(n + 1, false);
    for (auto x : graph[i])
    {
        if (!vis[x.first])
        {
            vector<int> temp;
            dfs(x.first, graph, vis, temp);
            int size = temp.size();
            ans += min(size, n - size) * 2 * x.second;
        }
    }
    return ans;
}
int main()
{

    vector<vector<pair<int, int>>> graph(5);

    graph[1].push_back({2, 3});

    graph[2].push_back({1, 3});
    graph[2].push_back({3, 2});
    graph[2].push_back({5, 4});

    graph[3].push_back({2, 2});
    graph[3].push_back({4, 2});

    graph[4].push_back({3, 2});

    cout << solve(1, graph, 5);

    return 0;
}