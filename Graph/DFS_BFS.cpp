#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool> &vis, vector<vector<int>> &graph)
{
    vis[i] = true;
    cout << i << " ";
    for (auto child : graph[i])
    {
        if (!vis[child])
            dfs(child, vis, graph);
    }
}

void bfs(vector<vector<int>> &graph, int i, vector<bool> &vis)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty())
    {
        int key = q.front();
        q.pop();
        cout << key << " ";
        for (auto x : graph[key])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }
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
    vis = vector<bool>(6, false);
    cout << endl;
    for (int i = 1; i <= 5; i++)
    {
        if (!vis[i])
            bfs(graph, i, vis);
    }
    cout << endl;

    return 0;
}

/*
1 2
1 5
2 3
2 4
5 4

*/