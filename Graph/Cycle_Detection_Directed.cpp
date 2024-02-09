// CYCLE DETECTION FOR DIRECTED USING BFS
#include <bits/stdc++.h>
using namespace std;

void BFS(int n, vector<vector<int>> v, vector<int> &output)
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
                    output.push_back(x);
                    q.push(x);
                }
            }
        }
    }
    cout << endl;
}
// CYCLE DETECTION USING DFS
void DFS(int i, vector<bool> &vis, vector<vector<int>> v, set<int> &st)
{
    vis[i] = true;
    for (auto x : v[i])
    {
        if (!vis[x])
        {
            DFS(x, vis, v, st);
        }
    }
    st.insert(i);
}
int main()
{
    vector<vector<int>> graph(5);
    graph[0].push_back(1);

    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(4);

    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(2);
    graph[3].push_back(4);

    graph[4].push_back(1);
    graph[4].push_back(3);

    int n = 5;
    vector<int> output;
    BFS(n, graph, output);
     for (int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << endl;
    vector<bool> vis(n + 1, false);
    cout << "Cycle Exists : ";
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        if (!vis[i])
            DFS(i, vis, graph, st);
        if (st.size() != n)
        {
            flag = true;
            break;
        }
    }
    cout << flag << endl;
    bool ans = output.size() <= n;
    cout << "Cycle Exists : " << ans << endl;

    return 0;
}
