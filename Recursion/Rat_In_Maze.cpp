//PRINT THE PATH TO REACH A CERTAIN POINT BY RAT
#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &board, int n, vector<string> &v, string &pattern)
{
    if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] == 0)
        return;

    if (i == n - 1 && j == n - 1)
    {
        v.push_back(pattern);
        return;
    }

    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        char output;
        if (x[k] == 0 && y[k] == -1)
            output = 'L';
        if (x[k] == -1 && y[k] == 0)
            output = 'U';
        if (x[k] == 0 && y[k] == 1)
            output = 'R';
        if (x[k] == 1 && y[k] == 0)
            output = 'D';
        int ni = i + x[k];
        int nj = j + y[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] != 0)
        {
            board[i][j] = 0;
            pattern += output;
            dfs(ni, nj, board, n, v, pattern);
            board[i][j] = 1;
            pattern.pop_back();
        }
    }
}
int main()
{
    vector<vector<int>> board{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int ans = 0, n = board.size();
    vector<string> v;
    string str = "";
    dfs(0, 0, board, n, v, str);
    for (auto x : v)
        cout << x << " ";

    return 0;
}
