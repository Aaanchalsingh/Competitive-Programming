// Randomized Quick Sort
#include <bits/stdc++.h>
using namespace std;

int get(int a, int b)
{
    return rand() % (a - b + 1) + a;
}
void getRandom(vector<int> &v)
{
    int n = v.size();
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % i + 1;
        swap(v[i], v[j]);
    }
}
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
void Quick_Sort(vector<int> &A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = Partition(A, low, high);
        Quick_Sort(A, low, mid);
        Quick_Sort(A, mid + 1, high);
    }
}
int main()
{
    vector<int> v{5, 4, 3, 2, 6, 7, 8, 1, 0, 9};
    getRandom(v);
    Quick_Sort(v, 0, v.size());
    for (auto x : v)
        cout << x << " ";

    return 0;
}
