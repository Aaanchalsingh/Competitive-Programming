// TRIPLET SUM
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2, 1, 4, 6, 3, 8, 7};
    int n = v.size(), key = 11, count = 0;
    int i = 0, j = 1, k = n - 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            if (v[i] + v[j] + v[k] <= key)
            {
                count += k - j - 1;
                j++;
                k--;
            }
            else
                k--;
        }
    }
    cout << count;
    return 0;
}