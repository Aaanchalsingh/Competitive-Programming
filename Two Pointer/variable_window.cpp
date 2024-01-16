// FIND MINIMUM LENGTH OF SUBARRY WHOSE SUM IS K
// VARIABLE SUBARRAY QUESTION
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{4, 2, 1, 6, 10, 3, 4};
    int n = v.size(), sum = 0, key = 7, ans = 1e9, j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        while (sum >= key)
        {
            if (sum == key)
                ans = min(ans, i - j + 1);
            sum -= v[j++];
        }
    }
    cout << ans << endl;

    // Another Approach
    // We merge the first condition to reduce the loop
    int i = 0; j = 0,ans=1e9,sum=0;
    while (j < n)
    {
        if (sum < key)
        {
            sum += v[++j];
            continue;
        }
        else if (sum == key)
        {
            int len = j - i + 1;
            ans = min(ans, len);
        }
        sum -= v[i++];
    }
    cout << ans << endl;
    return 0;
}