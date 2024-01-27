#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
    if (n == 1 || n == 2)
        return n;
    return f(n - 1) + (n - 1) * f(n - 2);
}
int main()
{
    vector<char> nums{'A', 'B', 'C', 'D'};
    int n = nums.size();
    cout << f(n);
}
//