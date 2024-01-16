// Smallest window containing both smallest and largest element
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 4, 6, 5, 1, 5, 2, 6, 4, 4, 2, 1, 5};
    int largest = 6, smallest = 1, ans = 1e9, lastmax = -1;
    int lastmin = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == largest)
            lastmax = i;
        else if (v[i] == smallest)
            lastmin = i;
        if(lastmax>-1 && lastmin>-1)ans = min(ans, abs(lastmax - lastmin));
    }
    cout << ++ans;
    return 0;
}