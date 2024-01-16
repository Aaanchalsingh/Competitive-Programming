#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sum = -1e9, cur = 0;
    for (auto x : nums)
    {
        cur += x;
        sum = max(sum, cur);
        if (cur < 0)
            cur = 0;
    }
    cout << sum;
    return 0;
}