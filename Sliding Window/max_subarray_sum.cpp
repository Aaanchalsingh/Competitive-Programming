// MAX SUBARRAY SUM WITH A GIVEN LENGTH k
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{-3, 2, 5, 1, 6, 3, -5};
    int n = v.size(), k = 4, sum = 0;
    for (int i = 0; i < k; i++)
        sum += v[i];
    int m = sum;
    int j = 0;
    for (int i = k; i <n ; i++)
    {
        if (sum > m)
        {
            m = sum;
        }
        sum -= v[j++];
        sum += v[i];
    }
    cout << m;
    return 0;
}