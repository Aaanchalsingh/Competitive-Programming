#include <bits/stdc++.h>
using namespace std;

int solve(string str, int limit)
{
    vector<int> ans;
    int n = str.size();
    if (n == 0)
        return 0;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[str[i]]++;
    for (auto x : mp)
        ans.push_back(x.second);
    sort(ans.begin(), ans.end(), greater<int>());
    n = ans.size();
    for (int i = 0; i < n; i++)
    {
        if (limit > 0)
        {
            if (ans[i] > limit)
            {
                ans[i] -= limit;
                break;
            }
            else
            {
                int key = limit;
                limit -= ans[i];
                ans[i] -= key;
            }
        }
        else
            break;
    }
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(ans[i] * ans[i]);
    }
    return cost;
}
int main()
{
    string str = "abcbcc";
    int limit = 3;
    cout << solve(str, limit);
    return 0;
}