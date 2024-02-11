#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &v, int i, int j, int m, int n, vector<int> &ans)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;

    int key = v[i][j];
    ans.push_back(key);
    if (i == m - 1)
    {
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    int sum = key + max({dfs(v, i + 1, j - 1, m, n, ans), dfs(v, i + 1, j, m, n, ans),
                         dfs(v, i + 1, j + 1, m, n, ans)});
    v[i][j] = 0;
    ans.pop_back();
    return sum;
}

int main()
{
    vector<vector<int>> adj{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int m = adj.size(), n = adj[0].size();
     vector<vector<int>> v=adj;
    for (auto x : adj)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    vector<int> ans;
    int a = dfs(v, 0, 0, m, n, ans);
    ans.clear();
    cout<<endl;
    int b = dfs(adj, 0, n - 1, m, n, ans);

    cout << a << " " << b;
    return 0;
}