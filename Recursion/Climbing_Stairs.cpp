#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>> &v, vector<int> &temp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        v.push_back(temp);
        return 1;
    }

    temp.push_back(n);
    int k = solve(n - 1, v, temp) + solve(n - 2, v, temp) + solve(n - 3, v, temp);
    temp.pop_back();
    return k;
}

int main()
{
    int n = 4;
    vector<vector<int>> v;
    vector<int> temp;
    solve(n, v, temp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << ",";
        cout << "]" << endl;
    }

    return 0;
}
