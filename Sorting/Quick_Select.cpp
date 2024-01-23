// QUICK SELECT O(N) Find Kth Smallest Element
#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int low, int high)
{
    int j = low - 1, pivot = v[high];
    for (int i = low; i < high; i++)
    {
        if (v[i] < pivot)
            swap(v[i], v[++j]);
    }
    swap(v[j + 1], v[high]);
    return j + 1;
}
int Quick_Select(vector<int> &A, int low, int high, int k)
{
    int p;
    if (low >= high)
        return -1;
    p = Partition(A, low, high);
    if (k == p)
        return A[p];
    if (p > k)
        Quick_Select(A, low, p - 1, k);
    else
        Quick_Select(A, p + 1, high, k);
}
int main()
{
    vector<int> v{5, 4, 3, 2, 6, 7, 8, 1, 0, 9};
    for (int i = 0; i < v.size(); i++)
        cout << Quick_Select(v, 0, v.size(), i) << " ";
    return 0;
}