#include <bits/stdc++.h>
using namespace std;

// JUST A LITTLE OPTIMEZED INSTEAD OF 4 LOOPS IN ISSAFE FUNCTION WE HAVE USED 4 MAP TO DO IT

bool isSafe(vector<vector<int>> &board, int row, int col, int n, unordered_map<int, int> &rowMap, unordered_map<int, int> &colMap, unordered_map<int, int> &leftDiagonalMap, unordered_map<int, int> &rightDiagonalMap)
{
    if (rowMap.count(row) || colMap.count(col) || leftDiagonalMap.count(row - col) || rightDiagonalMap.count(row + col))
        return false;

    return true;
}

void print(vector<vector<int>> &board)
{
    for (auto row : board)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<int>> &board, int i, int n, unordered_map<int, int> &rowMap, unordered_map<int, int> &colMap, unordered_map<int, int> &leftDiagonalMap, unordered_map<int, int> &rightDiagonalMap)
{
    if (i == n)
    {
        print(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, i, j, n, rowMap, colMap, leftDiagonalMap, rightDiagonalMap))
        {
            rowMap[i] = 1;
            colMap[j] = 1;
            leftDiagonalMap[i - j] = 1;
            rightDiagonalMap[i + j] = 1;

            board[i][j] = 1;
            solve(board, i + 1, n, rowMap, colMap, leftDiagonalMap, rightDiagonalMap);

            rowMap.erase(i);
            colMap.erase(j);
            leftDiagonalMap.erase(i - j);
            rightDiagonalMap.erase(i + j);
            board[i][j] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));

    unordered_map<int, int> rowMap;
    unordered_map<int, int> colMap;
    unordered_map<int, int> leftDiagonalMap;
    unordered_map<int, int> rightDiagonalMap;

    solve(board, 0, n, rowMap, colMap, leftDiagonalMap, rightDiagonalMap);
    return 0;
}
