#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for (auto i : v)
        cout << i;
    cout << endl;
}
void solve(int i, int n, vector<int> &v)
{
    if (i == n)
    {
        print(v);
        return;
    }
    v[i] = 0;
    solve(i + 1, n, v);
    v[i] = 1;
    solve(i + 1, n, v);
}
int main()
{
    int n = 4;
    // Approach 1
    for (int i = 0; i < 1 << n; i++)
    {
        bitset<32> b(i);
        cout << b.to_string().substr(32 - n) << endl;
    }
    // Approach 2
    vector<int> v(n, 0);
    solve(0, n, v);

    return 0;
}