// QUICK SORT O(NlogN)
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
void Quick_Sort(vector<int> &A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = Partition(A, low, high);
        Quick_Sort(A, low, mid-1);
        Quick_Sort(A, mid + 1, high);
    }
}
int main()
{
    vector<int> v{5, 4, 3, 2, 6, 7, 8, 1, 0, 9};
    Quick_Sort(v, 0, v.size() - 1);
    for (auto x : v)
        cout << x << " ";
    return 0;
}