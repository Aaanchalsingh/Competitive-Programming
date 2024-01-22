// Ath Magical Number
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A = 8, B = 2, C = 3;
    int low = 0, high = min(B, C) * A, mid = 0, ans = -1;
    int LCM = (B * C) / __gcd(B, C);
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int count = (mid / B) + (mid / C) - (mid / LCM);
        if (count == A)
        {
            ans = mid;
            break;
        }
        if (count > A)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans;
    return 0;
}