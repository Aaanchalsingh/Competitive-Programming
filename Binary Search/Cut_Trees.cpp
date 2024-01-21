// EKO Problem from SPOJ
#include <bits/stdc++.h>
using namespace std;
bool canweplace(int v[], int k, int target, int n)
{
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] - target > 0)
            sum += v[i] - target;
    }
    return sum >= k;
}
int main()
{
    int n = 5, v[] = {4, 42, 40, 26, 46}, k = 20, sum = 0, maxi = -1e9;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, v[i]);
    int low = 0, high = maxi, mid = 0, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (canweplace(v, k, mid, n))
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