// QUICK SELECT O(N) Find Kth Smallest Element
#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1, j = high - 1;
    while (i < j)
    {
        while (A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
            swap(A[i], A[j]);
    }
    swap(A[low], A[j]);
    return j;
}
int Quick_Select(vector<int> &A, int low, int high, int k)
{
    int mid;
    if (low < high)
    {
        mid = Partition(A, low, high);
        if (k == mid)
            return A[mid];
        if (mid > k)
            Quick_Select(A, low, mid, k);
        else
            Quick_Select(A, mid + 1, high, k);
    }
    else
        return -1;
}
int main()
{
    vector<int> v{5, 4, 3, 2, 6, 7, 8, 1, 0, 9};
    for (int i = 0; i < v.size(); i++)
        cout << Quick_Select(v, 0, v.size(), i + 1) << " ";
    return 0;
}