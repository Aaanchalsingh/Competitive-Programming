#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k = 3, n = 4;
    vector<vector<int>> v{{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (int i = 0; i < k; i++)
        minHeap.push({v[i][0], i});
    while (!minHeap.empty())
    {
        pair<int, int> p = minHeap.top();
    }

    return 0;
}
