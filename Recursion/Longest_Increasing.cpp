#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &v, int n)
{
    if (!(i >= 0 && i < n && j >= 0 && j < n))
        return 0;

    vector<int> x = {1, 1, -1, -1, 0, 0, 1, -1};
    vector<int> y = {1, -1, -1, 1, 1, -1, 0, 0};
    int ans = 0;

    for (int k = 0; k < x.size(); k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && v[ni][nj] - v[i][j] == 1)
        {
            int sublen = dfs(ni, nj, v, n);
            ans = max(ans, sublen);
        }
    }
    return ans + 1;
}

int main()
{
    vector<vector<int>> v{{1, 2, 3, 7}, {6, 9, 5, 10}, {0, 2, 2, 4}, {1, 5, 3, 11}};
    int ans = 0, n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = dfs(i, j, v, n);
            ans = max(ans, k);
        }
    }

    cout << ans;
    return 0;
}
