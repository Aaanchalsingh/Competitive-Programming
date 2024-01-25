// JOB SCHEDULING ALGORITHM
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v{{4, 20}, {1, 20}, {1, 100}, {1, 70}, {1, 60}};
    sort(v.begin(), v.end());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            pq.push(v[i][1]);
        else
        {
            if (pq.size() < v[i][0])
            {
                pq.push(v[i][1]);
            }
            else if (v[i][1] >= pq.top())
            {
                pq.pop();
                pq.push(v[i][1]);
            }
            else
                pq.push(v[i][1]);
        }
    }
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}