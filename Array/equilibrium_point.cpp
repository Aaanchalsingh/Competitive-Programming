// FIND EQUILIBRIUM INDEXES WHERE LEFT AND RIGHT SUM IS SAME
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{-7, 1, 5, 2, -4, 3, 0};
    int n = v.size(), sum = 0, left = 0, count = 0;
    for (auto x : v)
        sum += x;
    for (int i = 0; i < n; i++)
    {
        left += v[i];
        if (sum - left == left - v[i])
            count++;
    }
    cout << count;
    return 0;
}