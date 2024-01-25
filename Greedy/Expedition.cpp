// EXPEDITION SPOJ
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> v, int destination)
{
    priority_queue<pair<int, int>> pq;
    int n = v.size(), tank = 10, ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int curdistance = v[i + 1][0] - v[i][0];
        if (curdistance <= tank)
        {
            tank -= curdistance;
            pq.push({v[i][0], v[i][1]});
        }
        else
        {
            while (curdistance > tank && !pq.empty())
            {
                pair<int, int> nextstop = pq.top();
                pq.pop();
                ans++;
                tank += nextstop.second;
                tank -= curdistance;
            }
        }
    }
    int curdistance = destination - v[n - 1][0];
    if (curdistance <= tank)
        return ans;

    while (curdistance > tank && !pq.empty())
    {
        pair<int, int> nextstop = pq.top();
        pq.pop();
        ans++;
        tank += nextstop.second;
        tank -= curdistance;
    }
    if (curdistance > tank)
        return -1;
    return ans;
}
int main()
{
    vector<vector<int>> v{
        {10, 60}, {20, 30}, {30, 30}, {60, 40}};
    int n = v.size();
    cout << solve(v,100);
    return 0;
}