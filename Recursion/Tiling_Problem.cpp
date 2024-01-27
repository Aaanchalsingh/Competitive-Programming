// TILING PROBLEM (N X 4) Area
#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if (n < 4)
        return 1;
    return f(n - 1) + f(n - 2);
}
int main()
{
    int n = 5;
    cout << f(n);
    return 0;
}