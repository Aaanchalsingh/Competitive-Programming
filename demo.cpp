#include <bits/stdc++.h>
using namespace std;

int longest_Seq(vector<int> v, int n)
{
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] >= v[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> v{3, 2, 4, 1, 7, 8, 6, 10, 9};
    int n = v.size();
    cout << longest_Seq(v, n);
}