#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>> &board, int n, vector<string> &v)
{
    if (i == n - 1 && j == n - 1)
    {

        return 1;
    }
    if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0)
        return 0;

    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int ans = 0;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        board[i][j] = 0;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] != 0)
            ans += dfs(ni, nj, board, n,v);
        board[i][j] = 1;
    }
    return ans;
}

int main()
{
    vector<vector<int>> board{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int ans = 0, n = board.size();
    vector<string> v;
    dfs(0, 0, board, n, v);
    for (auto x : v)
        cout << x << " ";

    return 0;
}
