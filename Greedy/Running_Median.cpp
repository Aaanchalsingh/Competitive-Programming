// RUNNING MEDIAN SPOJ RMIT 295
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{2, 1, 9, 7, 5, 6, -2, -3};
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    max_heap.push(v[0]);
    int median = v[0];
    cout << median << " ";
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < median)
            max_heap.push(v[i]);
        else
            min_heap.push(v[i]);
        int maxsize = max_heap.size();
        int minsize = min_heap.size();
        if (abs(maxsize - minsize) > 1)
        {
            if (maxsize < minsize)
            {
                int x = min_heap.top();
                min_heap.pop();
                max_heap.push(x);
            }
            else
            {
                int x = max_heap.top();
                max_heap.pop();
                min_heap.push(x);
            }
        }
        maxsize = max_heap.size();
        minsize = min_heap.size();
        if (maxsize == minsize)
            median = (max_heap.top());
        else if (min_heap.size() > max_heap.size())
            median = min_heap.top();
        else if (min_heap.size() < max_heap.size())
            median = max_heap.top();
        cout << median << " ";
    }

    return 0;
}