// SUBSUMS - Subset Sums On SPOJ
/*Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{1, -2, 3};
    int low = -1, high = 2;
    int n = v.size(), count = 0;

    vector<int> sum1, sum2;
    for (int i = 0; i < (1 << n / 2); i++)
    {
        int sum = 0;
        for (int j = 0; j < n / 2; j++)
        {
            if (i & (1 << j))
            {
                sum += v[j];
            }
        }
        sum1.push_back(sum);
    }

    for (int i = 0; i < (1 << (n - n / 2)); i++)
    {
        int sum = 0;
        for (int j = n / 2; j < n; j++)
        {
            if (i & (1 << (j - n / 2)))
            {
                sum += v[j];
            }
        }
        sum2.push_back(sum);
    }
    sort(sum2.begin(), sum2.end());
    for (int i = 0; i < sum1.size(); i++)
    {
        auto it = lower_bound(sum2.begin(), sum2.end(), low - sum1[i]);
        int p = it - sum2.begin();
        it = upper_bound(it, sum2.end(), high - sum1[i]);
        int q = it - sum2.begin();
        count += (q - p);
    }

    cout << count << endl;

    return 0;
}
