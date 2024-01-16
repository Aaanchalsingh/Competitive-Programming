#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v{{1, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {1, 0, 1, 0}};
    int m = v.size(), n = v[0].size();
    vector<vector<int>> prefixsum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == 1)
                prefixsum[i][j] = 1 + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            else
                prefixsum[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << prefixsum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}