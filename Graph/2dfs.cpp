#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int p, vector<int> adj[], vector<int> &par)
{
    par[i] = p;
    for (auto x : adj[i])
    {
        if (x != p)
        {
            dfs(x, i, adj, par);
        }
    }
}
void dfs2(int i, vector<int> adj[], int &sum, int cur, vector<int> &par)
{
    if (i > cur)
        sum++;
    for (auto x : adj[i])
    {
        if (x != par[i])
        {

            dfs2(x, adj, sum, cur, par);
        }
    }
}
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> adj[n + 1];
    vector<int> par(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, adj, par);
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b;
        int sum = 0;
        dfs2(b, adj, sum, b, par);
        cout << sum << endl;
    }

    return 0;
}