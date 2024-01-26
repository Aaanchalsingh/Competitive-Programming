// SQRT OF A NUMBER
#include <bits/stdc++.h>
using namespace std;
int order_n(int n)
{
    int i = 0;
    for (i = 0; i * i <= n; i++)
    {
        if (i * i == n)
            return i;
    }
    return i - 1;
}
int order_logn(int n)
{
    int low = 0, end = n;
    while (low <= end)
    {
        int mid = low - low / 2 + end / 2;
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
            low = mid + 1;
        else
            end = mid - 1;
    }
    return end;
}
float order_n_precision(int n, int p)
{
    float low = 0, end = n, ans = -1;
    while (low <= end)
    {
        int mid = low - low / 2 + end / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
            low = mid + 1;
        else
            end = mid - 1;
    }
    if (ans == -1)
        ans = end;
    float increment = 0.1;
    for (int i = 0; i < p; i++)
    {
        while (ans * ans <= n)
        {
            ans += increment;
        }
        ans -= increment;
        increment = increment / 10; // 3.1//3.16//3.162
    }
    return ans;
}
int main()
{

    int sqrt = 10;
    cout << "The square root of " << sqrt << " is : " << order_n(sqrt) << " O(N)" << endl;
    cout << "The square root of " << sqrt << " is : " << order_logn(sqrt) << " O(LogN)" << endl;
    cout << "The square root of " << sqrt << " is : " << order_n_precision(sqrt, 3) << " With Precision" << endl;
    return 0;
}