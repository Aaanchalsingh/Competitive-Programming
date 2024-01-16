// CONTAINER WITH MOST WATER
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{3, 1, 5, 8, 6, 2, 7};
    int n = v.size(), j = n - 1, i = 0, m = 0;
    while (i < j)
    {
        int diff = abs(j - i);
        m = max(m, diff * min(v[j], v[i]));
        cout<<v[i]<<" "<<v[j]<<" "<<m<<endl;
        if (v[j] > v[i])
            i++;
        else if (v[j] < v[i])
            j--;
        else
        {
            j--;
            i++;
        }
    }
    cout << m;
    return 0;
}