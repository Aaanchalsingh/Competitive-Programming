// SPOJ Question PRATA
#include <bits/stdc++.h>
using namespace std;
bool canweplace(vector<int> &v, int k, int target)
{
    int n = v.size(), sum = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = 0, sum = 0;
        cout << v[i] << ":";
        while (sum < target)
        {
            cur += v[i];
            sum += cur;
            if (sum > target)
                break;
            cout << sum << " ";
            k--;
        }
        cout << endl;
        if (k <= 0)
            return true;
    }
    return false;
}

//ALTERNATIVE APPROACH WHICH USES BINARY SEARCH FOR SOLVING
//Here we use a formula that no. of prata cooked by chef with rank R in T minutes is the maximum value that satisfy this equation n*(n+1)<=(2*T/R)

bool canweplace2(vector<int> &v, int k, int target)
{
    int n = v.size(), maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int low = 1, high = target - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (mid * (mid + 1) > ((2 * target) / v[i]))
            {
                maxi = mid - 1;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        k -= maxi;
        if (k <= 0)
            return true;
    }
    return false;
}
int main()
{
    int n = 4, k = 0;
    vector<int> v{1, 2, 3, 4};
    sort(v.begin(), v.end());
    int low = 0, high = ((k / 2) * (v[0] + k)), mid = 0, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (canweplace(v, k, mid))
        {
            cout << "RUN:" << mid << endl;
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans;
    return 0;
}