#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    vector<int> v;
    int size;

    Heap()
    {
        size = 0;
    }

    void push(int data)
    {
        int n = v.size(), i = n;
        v.push_back(data);
        while (i > 0 && v[i] > v[i / 2])
        {
            swap(v[i], v[i / 2]);
            i = i / 2;
        }
        size++;
    }

    void heapify(int i)
    {
        int n = size;
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
            heapify(largest);
        }
    }

    void pop()
    {
        int n = size;
        if (n == 0)
            return;
        else
        {
            size--;
            swap(v[size], v[0]);
            heapify(0);
        }
    }

    int top()
    {
        return v[0];
    }
};

int main()
{
    Heap obj;
    for (int i = 0; i < 10; i++)
        obj.push(i + 1);
    obj.push(-1);
    obj.push(100);
    obj.push(5);

    cout << "Original Max Heap: ";
    for (auto x : obj.v)
        cout << x << " ";
    cout << endl;

    cout << "Sorted Order: ";
    while (obj.size > 0)
        obj.pop();
    for (auto x : obj.v)
        cout << x << " ";
    cout << endl;
    return 0;
}
