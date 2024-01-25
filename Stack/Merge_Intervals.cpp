// MERGE INERVALS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = v.size();
    sort(v.begin(), v.end());
    stack<pair<int, int>> st;
    st.push({v[0][0], v[0][1]});
    for (int i = 1; i < n; i++)
    {
        int start = st.top().first;
        int end = st.top().second;
        if (v[i][0] <= end)
        {
            st.top().second = max(st.top().second, v[i][1]);
        }
        else
        {
            st.push({v[i][0], v[i][1]});
        }
    }
    while (!st.empty())
    {
        cout << "[" << st.top().first << "," << st.top().second << "]" << endl;
        st.pop();
    }
    return 0;
}