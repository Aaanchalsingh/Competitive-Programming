#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{100, 80, 120, 70, 60, 75, 85};
    int n = v.size();
    vector<int> ans(n, 1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] < v[i]) st.pop();
        if (st.empty()) ans[i] = i + 1;
        if(!st.empty()) ans[i] = i - st.top();
        st.push(i);
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
//HOMEWORK
// 1. MAXIMUM SUBARRAY SUM
// 2. HISTOGRAM AREA PROBLEM
// 3. MAXIMUM AREA OF THE RECTANGLE WITH ALL 1S IN 2D ARRAY

