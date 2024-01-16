#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{5, 1, 3, 8, 7, 2, 6, 9};
    int n = v.size();
    int k = 14;
    sort(v.begin(), v.end());
    int j = 1, i = 0;
    while (i < n)
    {
        if (j == n )
        {
            i++;
            j = i + 1;
        }
        if (v[i] + v[j] == k)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j++;
        }
        else if (v[i] + v[j] > k)
            j++;
        else
            i++;
    }
    return 0;
}