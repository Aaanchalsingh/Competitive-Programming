// FRACTIONAL KNAPSACK
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}
int main()
{
    vector<vector<int>> v{{0, 60, 10}, {0, 100, 20}, {0, 120, 30}};
    for (int i = 0; i < v.size(); i++)
        v[i][0] = v[i][1] / v[i][2];
    sort(v.begin(), v.end(), cmp);
    int n = v.size(), w = 50, max_value = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i][2])
        {
            profit += v[i][1];
            cout << profit << endl;
            w -= v[i][2];
        }
        else
        {
            profit += w * v[i][0];
            break;
        }
    }
    cout << profit;

    return 0;
}