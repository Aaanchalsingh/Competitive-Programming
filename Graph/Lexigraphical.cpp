#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<bool> &vis, vector<int> graph[])
{
    vis[i] = true;
    char p = i + 'a';
    cout << p << " ";
    for (auto child : graph[i])
    {
        if (!vis[child])
            dfs(child, vis, graph);
    }
    return;
}
int main()
{
    int n = 10, m = 10;
    char S = 'a';
    vector<vector<char>> v{{'a', 'y'}, {'a', 'z'}, {'a', 'p'}, {'p', 'c'}, {'p', 'b'}, {'y', 'm'}, {'y', 'l'}, {'z', 'h'}, {'z', 'g'}, {'z', 'i'}};
    sort(v.begin(), v.end());
    vector<int> adj[27];
    for (int i = 0; i < n; i++)
    {
        adj[v[i][0] - 'a'].push_back(v[i][1] - 'a');
    }
    vector<bool> vis(27, false);
    dfs(0, vis, adj);

    return 0;
}