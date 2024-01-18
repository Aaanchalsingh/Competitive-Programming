#include <bits/stdc++.h>
using namespace std;
bool get_ith_bit(int k, int x)
{
    return (1 << k) & x;
}
int set_ith_bit(int k, int x)
{
    return x | (1 << k);
}
int clear_ith_bit(int i, int x)
{
    return x & ~(1 << i);
}
int countsetbits(int n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}
int update_bits(int x, int i)
{
    if (get_ith_bit(i, x))
        clear_ith_bit(i, x);
    else
        set_ith_bit(i, x);
}
int clear_range_of_bits(int l, int r, int n)
{
    int range = (((1 << (l - 1)) - 1) ^ ((1 << r) - 1));
    return (n | range);
}
int main()
{
    int x = 7;
    cout << get_ith_bit(2, x);
    cout << set_ith_bit(2, x);
    cout << clear_ith_bit(2, x);
    cout << countsetbits(5);
    return 0;
}