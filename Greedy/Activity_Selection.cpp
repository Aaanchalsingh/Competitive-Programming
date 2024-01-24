#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> start{1,3,2,5};
    vector<int> end{2,4,3,6};
    vector<int> ans;
    int n = start.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
        pq.push(make_pair(end[i], start[i]));

    auto it = pq.top();
    int currStart = it.second;
    int currEnd = it.first;
    pq.pop();
    ans.push_back(currStart);

    while (!pq.empty())
    {
        auto it = pq.top();
        int newStart = it.second;
        int newEnd = it.first;
        pq.pop();

        if (newStart >= currEnd)
        {
            ans.push_back(newStart);
            currEnd = newEnd;
        }
    }

    for (auto x : ans)
        cout << x << " ";

    return 0;
}
