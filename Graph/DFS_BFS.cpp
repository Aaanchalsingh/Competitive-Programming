#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<bool> &vis, vector<vector<int>> graph)
{
    vis[i] = true;
    cout << i << " ";
    for (auto child : graph[i])
    {
        if (!vis[i])
            dfs(child, vis, graph);
    }
}
void bfs(){

}
int main()
{
    vector<vector<int>> graph(6);
    vector<bool> vis(6, false);
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 1; i <= 5; i++)
    {
        if (!vis[i])
            dfs(i, vis, graph);
    }

    return 0;
}