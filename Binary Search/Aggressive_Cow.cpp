// AGGRESIVE COWS
// MAXIMIZE THE MINIMUM DISTANCE
#include <bits/stdc++.h>
using namespace std;
bool canweplace(vector<int> &v, int k, int mid)
{
    int n = v.size(), lastcow = v[0];
    k--;
    for (int i = 1; i < n; i++)
    {
        if ((v[i] - lastcow >= mid))
        {
            lastcow = v[i];
            k--;
        }
    }

    if (k <= 0)
        return true;
    return false;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v{1, 2, 4, 8, 9};
    sort(v.begin(), v.end());
    int low = 0, high = v[v.size() - 1] - v[0], mid = 0, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (canweplace(v, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans;
    return 0;
}