#include <bits/stdc++.h>
using namespace std;

void BFS(int n, vector<vector<int>> v)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto x : v[i])
            indegree[x]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<bool> vis(n, false);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        vis[top] = true;
        cout << top << " ";
        for (auto x : v[top])
        {
            if (!vis[x])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
    }
    cout << endl;
}
void DFS(int i, vector<bool> &vis, vector<vector<int>> v, vector<int> &output)
{
    vis[i] = true;
    for (auto x : v[i])
    {
        if (!vis[x])
            DFS(x, vis, v, output);
    }
    output.push_back(i);
}
int main()
{
    int n = 6;
    vector<vector<int>> graph(n);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);
    BFS(n, graph);
    vector<int> output;
    vector<bool> vis(n, false);
    DFS(0, vis, graph, output);
    reverse(output.begin(), output.end());
    for (auto i : output)
    {
        cout << i << " ";
    }
    return 0;
}
