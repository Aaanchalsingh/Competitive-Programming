#include <iostream>
#include <vector>
using namespace std;

vector<int> x{-1, 0, 0, 1};
vector<int> y{0, -1, 1, 0};

void dfs(int i, int j, vector<vector<char>> &graph, int m, int n, char dest, char sr)
{
    if (i < 0 || i >= m || j < 0 || j >= n || graph[i][j] != sr)
        return;
    graph[i][j] = dest;
    for (int k = 0; k < 4; k++)
    {
        int a = i + x[k];
        int b = j + y[k];
        if (a >= 0 && a < m && b >= 0 && b < n)
        {
            dfs(a, b, graph, m, n, dest, sr);
        }
    }
}

vector<vector<char>> fill(int m, int n, vector<vector<char>> grid)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'O')
                grid[i][j] = '?';
        }
    }
    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, grid, m, n, 'O', '?');
    }
    for (int i = 0; i < n; i++)
    {
        dfs(0, i, grid, m, n, 'O', '?');
    }
    for (int i = 0; i < m; i++)
    {
        dfs(i, n - 1, grid, m, n, 'O', '?');
    }
    for (int i = 0; i < n; i++)
    {
        dfs(m - 1, i, grid, m, n, 'O', '?');
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '?')
                grid[i][j] = 'X';
        }
    }
    return grid;
}

int main()
{
    int m = 4, n = 4;
    vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'X', 'O', 'X'},
                                 {'X', 'O', 'X', 'X'}};

    cout << "Original Grid:" << endl;
    for (const auto &row : grid)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << endl;

    grid = fill(m, n, grid);

    cout << "Modified Grid:" << endl;
    for (const auto &row : grid)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
