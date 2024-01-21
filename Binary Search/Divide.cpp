// Maximize the minimum Sum
// You have k friends divide in such a way that you get minimum now maximize your part
#include <bits/stdc++.h>
using namespace std;
bool canweplace(vector<int> &v, int k, int target)
{
    int n = v.size(), sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum >= target)
        {
            k--;
            sum = 0;
        }
    }
    // cout << target << " " << k<<endl;
    return k <= 0;
}
int main()
{
    int n = 6, k = 1, sum = 0;
    vector<int> v{6, 8, 4, 2, 1, 7};
    for (auto x : v)
        sum += x;
    sort(v.begin(), v.end());
    int low = 0, high = sum, mid = 0, ans = -1;
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