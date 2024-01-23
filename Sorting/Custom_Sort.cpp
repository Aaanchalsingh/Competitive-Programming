#include <bits/stdc++.h>
using namespace std;
class Cab
{
public:
    int x;
    int y;
    Cab()
    {
        x = 0;
        y = 0;
    }
};
class cabCompare(Cab a, Cab b)
{
public:
    return a.x + a.y > b.x + b.y;
};

Cab findClosestElements(vector<int> v, int k, int x)
{
    priority_queue<Cab, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());

    return ans;
}
int main()
{
    vector<int> v = {3, 8, 5, 2, 7, 4, 6, 9};
    cout << findClosestElements(v, 8, 3);
}