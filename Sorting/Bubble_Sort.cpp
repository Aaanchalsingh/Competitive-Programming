// BUBBLE SORT
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
void recursion(vector<int> &v, int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            swap(v[i], v[i + 1]);
        }
    }
    recursion(v, n - 1);
}
void best(vector<int> &v, int n, int i)
{
    if (n <= 1)
        return;
    if (i == n - 1)
    {
        best(v, n - 1, 0);
        return;
    }
    if (v[i] > v[i + 1])
        swap(v[i], v[i + 1]);
    best(v, n, i + 1);
}
int main()
{
    vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1};
    // bubble_sort(v);
    // recursion(v, v.size());
    best(v, v.size(), 0);
    for (auto x : v)
        cout << x << " ";
    return 0;
}