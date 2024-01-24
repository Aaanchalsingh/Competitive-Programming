#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> start{1, 3, 0, 5, 8, 5};
    vector<int> end{2, 4, 6, 7, 9, 9};
    int ans = 0, n = start.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
        pq.push({end[i], start[i]});
    auto it = pq.top();
    int currStart = it.second;
    int currEnd = it.first;
    pq.pop();
    ans++;
    while (!pq.empty())
    {
        auto it = pq.top();
        int newStart = it.second;
        int newEnd = it.first;
        pq.pop();

        if (newStart > currEnd)
        {
            ans++;
            currEnd = newEnd;
        }
    }
    cout << ans;
    // Another Approach
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(end[i], start[i]));
    sort(v.begin(), v.end());
    int x = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > x)
        {
            ans++;
            x = v[i].first;
        }
    }
    cout<< ans;

    return 0;
}
