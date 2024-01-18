// PRINT ALL SUBSETS USING BIT MANIPULTION
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 3, 2};
    int n = v.size(); // since n elements can generate 2^n subsets
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << v[j] << ", ";
        }
        cout << endl;
    }
    /*  2   1   0
    0   0   0   0  {}
    1   0   0   1  {1}
    2   0   1   0  {2}
    3   0   1   1  {1,2}
    4   1   0   0  {3}
    5   1   0   1
    6   1   1   0
    7   1   1   1
    */

    return 0;
}