// TOTAL NUMBER OF BST WITH N NODES
// WITHOUT USING CATALAN NUMBER 2NCN/N+1
#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    int ans = 0;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        ans += f(i - 1) * f(n - i);
    }
    return ans;
}
int main()
{
    int n = 3;
    cout << f(n);
    return 0;
}