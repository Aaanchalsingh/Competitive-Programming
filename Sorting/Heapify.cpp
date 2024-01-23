// Heap Creation
#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    vector<int> v;
    void push(int data)
    {
        int n = v.size(), i = n;
        v.push_back(data);
        while ((i >= 1) and (v[i] > v[i / 2]))
        {
            swap(v[i], v[i / 2]);
            i = i / 2;
        }
    }
    void heapify()
    {
        int n = v.size() - 1, i = 0;
        while (i <= n)
        {
            int largest = i;
            if (i * 2 <= n && v[i] < v[i * 2])
                largest = i * 2;

            if (i * 2 + 1 <= n && v[largest] < v[i * 2 + 1])
                largest = i * 2 + 1;
            if (largest != i)
            {
                swap(v[i], v[largest]);
                i = largest;
            }
            else
                break;
        }
    }
    void pop()
    {
        int n = v.size();
        if (n == 0)
            return;
        else
        {
            int k = v[0];
            swap(v[n - 1], v[0]);
            v.pop_back();
            for (auto x : v)
                cout << x << " ";
            cout << endl;
            heapify();
            v.push_back(k);
            for (auto x : v)
                cout << x << " ";
            cout << endl;
        }
    }
    int top()
    {
        return v[0];
    }
    /*
    Creating/Building a heap inplace O(N) Time Complexity
    heapsort O(NLogN) but inplace remove it like before in this code
     for(int i=n/2;i>=0;i--){
        heapify(i);
    }
    */
};
int main()
{
    Heap obj;
    for (int i = 0; i < 10; i++)
        obj.push(i + 1);
    for (int i = 0; i < 10; i++)
        obj.pop();

    return 0;
}