#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> v, int destination)
{
    priority_queue<int> pq;
    int n = v.size(), tank = 10, ans = 0;

    for (int i = 0; i < n;)
    {
        int curdistance = (i == 0) ? v[i][0] : v[i][0] - v[i - 1][0];
        if (curdistance <= tank)
        {
            tank -= curdistance;
            pq.push(v[i][1]);
            i++;
        }
        else
        {
            if (pq.empty())
                return -1;

            tank += pq.top();
            pq.pop();
            ans++;
        }
    }

    int curdistance = destination - v[n - 1][0];
    if (curdistance <= tank)
        return ans;

    while (curdistance > tank && !pq.empty())
    {
        tank += pq.top();
        pq.pop();
        ans++;
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
    cout << solve(v, 100);
    return 0;
}
