// calc. no. of pairs (i,j) such that a[i]=='a' && a[j]=='g' and i<j
//  arr = g s a g l a a a e g a
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a = "gsaglaaaega";
    int n = a.size(), ans = 0, countg = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 'g')
            countg++;
        else if (a[i] == 'a')
        {
            ans = ans + countg;
        }
    }
    cout << ans;

    return 0;
}