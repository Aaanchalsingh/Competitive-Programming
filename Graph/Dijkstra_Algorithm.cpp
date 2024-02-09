/*
1.DIJKSTRA ALGORITHM
2.Rod Cutting
3.Minmum path sum
4.Cheapest flight with k stops
*/
#include <bits/stdc++.h>
using namespace std;

void path(vector<vector<int>> v)
{
    int n = v.size();
    vector<int> dist(n + 1, 1e9);
    dist[0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<bool> vis(n, false);
    while (!q.empty())
    {
        int sr = q.front().first;
        int wt = q.front().second;
        q.pop();
        vis[sr] = true;
        for (auto x : v[sr])
        {
            if (!vis[x])
            {
                if (wt + v[sr][x] < dist[x])
                {
                    dist[x] = wt + v[sr][x];
                    q.push({x, dist[x]});
                }
            }
        }
    }
    for (int i = 1; i <= dist.size(); i++)
        cout << dist[i] << " ";
}
int main()
{

    return 0;
}