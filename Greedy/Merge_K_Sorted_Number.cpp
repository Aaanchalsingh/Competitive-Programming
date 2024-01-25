// MERGE K SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k = 3, n = 4;
    vector<vector<int>> v{{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    priority_queue<vector<int>, vector<vector<int>>, greater<int>> min_heap;
    for (int i = 0; i < k; i++)
        min_heap.push({v[i][0], i});
    for (int i = 0; i < n; i++)
    {
        if (!min_heap.empty())
            cout << min_heap.top().first << " ";
        min_heap.pop();
        min_heap.push({v[i][0], i});
    }

    return 0;
}