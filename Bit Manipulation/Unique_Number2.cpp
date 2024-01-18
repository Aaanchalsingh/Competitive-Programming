// FIND A UNIQUE NUMBER IN AN ARRAY CONTAINING TRIPLETS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{7, 7, 5, 7, 2, 2, 2};
    int n = v.size(), ans = 0, sum = 0;
    for (int i = 0; i < 32; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += (v[j] & 1);
            v[j] >>= 1;
        }
        ans += ((sum % 3) << i);
    }
    cout << ans;
    return 0;
    // simply keep a check over all one in each number
    //  4 2 1
    //  1 1 1
    //  1 1 1
    //  1 0 1
    //  1 1 1
    //  0 1 0
    //  0 1 0
    //  0 1 0
    //  4 6 4
    //  take mod with 3 for each number 101 which in decimal is 5

    // SUBSUM
    // count the number subset in between range l to r having sum k;
}