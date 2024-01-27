// GENEREATE PARENTHESIS
#include <bits/stdc++.h>
using namespace std;
void solve(int n, int open, int close, string s, int i, vector<string> &v)
{
    if (i == 2 * n)
    {
        v.push_back(s);
        s = "";
        return;
    }
    if (open < n)
    {
        solve(n, open + 1, close, s + "(", i + 1, v);
    }
    if (open > close)
    {
        solve(n, open, close + 1, s + ")", i + 1, v);
    }
}
int main()
{
    int n = 3;
    vector<string> ans;
    solve(n, 0, 0, "", 0, ans);
    for (auto x : ans)
        cout << x << endl;
    return 0;
}