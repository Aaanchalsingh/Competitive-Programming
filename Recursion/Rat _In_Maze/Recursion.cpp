#include <bits/stdc++.h>
using namespace std;

// RAT IN A MAZE WITH HURDLES
// PRINT THE PATH TO REACH A CERTAIN POINT BY RAT
// FOR COUNTING INSTEAD OF VOID TAKE INT AND RETURN 1 WHEN YOU WERE EARLIER PRINTING

// PRINT IN ALL 4 SIDES
void dfs(int i, int j, vector<vector<int>> board, int n, vector<string> &v, string &pattern)
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

// MOVE IN ALL 8 SIDES
int dfs_8_Sides(int i, int j, vector<vector<int>> board, int n)
{
    if (i < 0 || j < 0 || i > n || j > n || board[i][j] == 0)
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    int ans = 0;
    vector<int> x{-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> y{0, 1, 1, 1, 0, -1, -1, -1};
    for (int k = 0; k < 8; k++)
    {
        int ni = i + x[k];
        int nj = j + y[k];
        board[i][j] = 0;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == 1)
            ans += dfs_8_Sides(ni, nj, board, n);
        board[i][j] = 1;
    }
    return ans;
}
int main()
{
    vector<vector<int>> board{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int ans = 0, n = board.size();
    string str = "";
    vector<string> v;
    dfs(0, 0, board, n, v, str);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    cout << dfs_8_Sides(0, 0, board, n) << endl;
    return 0;
}
