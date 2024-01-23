// FORM LARGEST NUMBER USING
// LEETCODE 179
// Arrange them such that they form the largest number and return it.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    string x = to_string(a);
    string y = to_string(b);
    return (x + y) > (y + x);
}
int main()
{
    vector<int> v{1, 33, 332};
    sort(v.begin(), v.end(), cmp);
    string ans = "";
    if (v[0] == 0)
        ans = "0";
    else
    {
        for (auto x : v)
            ans += to_string(x);
    }
    cout << ans;
    return 0;
}