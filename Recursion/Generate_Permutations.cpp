// GENERATE PERMUTATIONS
#include <bits/stdc++.h>
using namespace std;
void solve(string &key, int i, vector<string> &ans)
{
    if (i == key.size())
    {
        ans.push_back(key);
        return;
    }
    for (int x = i; x < key.size(); x++)
    {
        swap(key[i], key[x]);
        solve(key, i + 1, ans);
        swap(key[i], key[x]);
    }
}
string next_permutations(string s)
{
    int n = s.size(), i1 = -1, i2 = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i + 1] > s[i])
        {
            i1 = i;
            break;
        }
    }
    if (i1 == -1)
        reverse(s.begin(), s.end());
    else
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[j] > s[i1])
            {
                swap(s[i1], s[j]);
                break;
            }
        }
    }

    reverse(s.begin() + i1 + 1, s.end());
    return s;
}
int main()
{
    string key = "ABC";
    vector<string> ans;
    solve(key, 0, ans);
    for (auto x : ans)
        cout << x << endl;
    cout << next_permutations(key);

    return 0;
}