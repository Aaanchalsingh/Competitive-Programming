#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{15, -1, 7, 2, 5, 4, 2, 3};
    int n = v.size() - 1;
    int curmax = 0, leader = 0;
    for (int i = n; i >= 0; i--)
    {
        if (v[i] > curmax)
        {
            curmax = v[i];
            leader++;
        }
    }
    cout << leader;
    return 0;
}