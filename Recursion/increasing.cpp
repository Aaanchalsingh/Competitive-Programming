// INCREASING RECURSION
#include <bits/stdc++.h>
using namespace std;
void decreasing(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    return decreasing(n - 1);
}
void increasing(int n)
{
    if (n == 0)
        return;
    increasing(n - 1);
    cout << n << " ";
}
int main()
{
    int n = 10;
    decreasing(n);
    cout << endl;
    increasing(n);
    return 0;
}