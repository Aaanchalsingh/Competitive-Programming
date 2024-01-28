#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &v)
{
    if (n == 0)
    {
        for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
        cout << endl;
        return;
    }
    else if (n < 0) return;
    for (int i = 1; i <= 3; ++i)
    {
        v.push_back(i);
        solve(n - i, v);
        v.pop_back();
    }
}

int main()
{
    int n = 5;
    vector<int> temp;
    solve(n, temp);
    return 0;
}
