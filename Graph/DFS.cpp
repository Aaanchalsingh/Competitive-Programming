#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<bool> &vis)
{

}
int main()
{
    vector<vector<int>> graph;
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
            dfs(i, vis);
    }

    return 0;
}