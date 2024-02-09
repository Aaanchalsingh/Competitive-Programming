#include <bits/stdc++.h>
using namespace std;

void path(vector<vector<int>> v[], int n)
{
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
    vector<bool> vis(n, false);
    while (!st.empty())
    {
        auto it = *st.begin();
        int wt = it.first;
        int sr = it.second;
        st.erase(it);
        if (vis[sr])
            continue;
        vis[sr] = true;
        for (auto edge : v[sr])
        {
            int src = edge[0];
            int weight = edge[1];
            if (weight + wt < dist[src])
            {
                dist[src] = weight + wt;
                st.insert({dist[src], src});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
}

int main()
{
    vector<vector<int>> graph[] = {
        {{1, 1}, {2, 6}},
        {{2, 3}, {0, 1}},
        {{1, 3}, {0, 6}}};
    path(graph, 3);
    return 0;
}
