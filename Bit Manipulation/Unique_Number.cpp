// Find 2 Unique number in the array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{3, 7, 3, 2, 2, 11, 5, 9, 9, 5};
    vector<int> final;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans ^= v[i];
    }
    int og = ans;
    int i = 0, key = 0;
    while (ans)
    {
        if (ans & 1)
        {
            key = i;
            break;
        }
        ans = ans >> 1;
        i++;
    }
    for (int j = 0; j < v.size(); j++)
    {
        if ((v[j] >> i) & 1)
        {
            final.push_back(v[j]);
        }
    }
    ans = 0;
    for (int i = 0; i < final.size(); i++)
    {
        ans ^= final[i];
    }
    int k = ans ^ og;
    cout << ans << " " << k;

    return 0;
}