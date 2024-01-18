// FIND A UNIQUE NUMBER IN AN ARRAY CONTAINING TRIPLETS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{7, 7, 5, 7, 2, 2, 2};
    vector<int> sum(3, 0);
    int n = v.size(), k = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = v[i];
        k=0;
        while (cur)
        {
            sum[k] += (cur & 1) % 3;
            cur >>= 1;
            k++;
        }
    }
    for (auto x : sum)
        cout << (x)%3 << " ";

    return 0;
    //SUBSUM
    //count the number subset in between range l to r having sum k;
}