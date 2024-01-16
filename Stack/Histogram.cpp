#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3, 1};
    int n = v.size(), area = 0;
    vector<int> left(n, 0), right(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top() + 1;
        s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top() - 1;
        else
            right[i] = n - 1;
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        area = max(area, (right[i] - left[i] + 1) * v[i]);
    cout << area;
    return 0;
}