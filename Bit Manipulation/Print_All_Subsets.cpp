// PRINT ALL SUBSETS USING BIT MANIPULTION
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 3, 2};
    int n = v.size();// 2^n
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                cout << v[j] << ", ";
        }
        cout << endl;
    }
    return 0;
}
//Find unique number where array containing 3 duplcates;