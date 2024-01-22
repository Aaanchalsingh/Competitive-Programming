// Find Unique Element in an array containing other element twice
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 1, 2, 2, 3, 3, 6, 6, 4, 5, 5, 7, 7};
    int n = v.size(), low = 0, high = n, mid = 0, ans = -1;
    if (v[low] != v[low + 1])
        ans = v[low];
    else if (v[high - 1] != v[high - 2])
        ans = v[high - 1];
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((mid < n - 1) && (mid > 0) && v[mid] != v[mid + 1] && v[mid] != v[mid - 1])
        {
            ans = v[mid];
            break;
        }
        else if (mid & 1)
        {
            if ((mid > 0) && v[mid] == v[mid - 1])
                low = mid + 2;
            else
                high = mid - 1;
        }
        else
        {
            if ((mid < n - 1) && v[mid] == v[mid + 1])
                low = mid + 2;
            else
                high = mid - 1;
        }
    }
    cout << ans;
    return 0;
}