// Box  Stalking Problem With Rotation
// Variant of Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;
void Generate_All_Possibilties(vector<vector<int>> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        int x = v[i][0];
        int y = v[i][1];
        int z = v[i][2];
        for (int j = 0; j < n; j++)
        {
            vector<int> temp;
            temp.push_back(v[i][j]);
            for(int  k=0;k<=2;k++){
                if(k!=j){
                    if(v[i][k])
                }
            }


        }
    }
}

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] > v2[0];
}
int main()
{
    vector<vector<int>> v{{10, 4, 3}, {8, 12, 7}, {5, 13, 6}, {4, 1, 20}};
    Generate_All_Possibilties(v);
    int n = v.size(), ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    sort(v.begin(), v.end(), sortcol);
    for (int i = 0; i < n; i++)
    {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int length = v[i][0];
        int width = v[i][1];
        int height = v[i][2];
        dp[i][0] = length;
        dp[i][1] = width;
        dp[i][2] = height;
        for (int j = i - 1; j >= 0; j--)
        {
            if ((dp[j][0] > length && dp[j][1] > width))
            {
                dp[i][2] = max(dp[i][2], dp[j][2] + height);
                ans = max(dp[i][2], ans);
            }
        }
    }
    cout << ans;

    return 0;
}