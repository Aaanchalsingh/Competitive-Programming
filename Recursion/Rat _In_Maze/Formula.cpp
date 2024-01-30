// RAT IN A MAZE WITHOUT HURDLES
// REDUCING THE COMPLEXITY OF TWO FOR LOOPS AND MAKING THE COMPLEXITY O(N) FROM O(N)^2 BY USING THE FORMULA
/*Rat maze problem 2
assumption: no obstacle in between
Moves - only right or bottom  i.e(i,j+1) or(i+1,j)
1. find no of paths from start to dest.
2.Print all paths.*/

#include <bits/stdc++.h>
using namespace std;

long long fact(int num)
{
    if (num <= 1)
        return 1;
    return num * fact(num - 1);
}

long long calculateWays(int n, int m)
{
    long long ans = fact(n + m - 2) / (fact(n - 1) * fact(m - 1));
    return ans;
}
// total rows travel for ith row =m-1
//  total cols travel for ith col = n-1
// total combination of paths will be fact(m-1+n-1)/fact(m-1)*fact(n-1)
// O(n)
int main()
{
    int n = 5, m = 6;
    cout << calculateWays(n, m);
    return 0;
}