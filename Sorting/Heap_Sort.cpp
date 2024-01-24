#include <bits/stdc++.h>
using namespace std;

void heapify(int i, int n, vector<int> &v)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(largest, n, v);
    }
}

void buildMaxHeap(vector<int> &v)
{
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, n, v);
    }
}

void heapSort(vector<int> &v)
{
    int n = v.size();
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(0, i, v);
    }
}
int main()
{
    vector<int> v{2, 1, 3, 7, 5, 3, 2, 5, 89, 9, 4, 23};
    int n = v.size();

    // BUILDING HEAP IN PLACE
    buildMaxHeap(v);
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    heapSort(v);

    cout << "Sorted Array: ";
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
