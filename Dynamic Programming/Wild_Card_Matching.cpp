#include <bits/stdc++.h>
using namespace std;
bool solve(string s1, string s2, int m, int n)
{
    if (m < 0 && n < 0)
        return true;
    if (m < 0 || n < 0)
        return false;
    if ((s1[m - 1] == s2[n - 1]) || (s1[m - 1] == '?'))
        return solve(s1, s2, m - 1, n - 1);
    else if (s1[m - 1] == '*')
    {
        return solve(s1, s2, m, n - 1) || solve(s1, s2, m - 1, n);
    }
}
int main()
{
    string s1 = "*ab?";
    string s2 = "abc";
    cout << solve(s1, s2, s1.size(), s2.size());
    return 0;
}