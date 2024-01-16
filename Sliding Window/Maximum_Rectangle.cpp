#include <bits/stdc++.h>
using namespace std;
int histogram(vector<int> &v)
{
    int n = v.size();
    stack<int> st;
    vector<int> prev(n, 0), next(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] >= v[i])
            st.pop();
        if (!st.empty())
            prev[i] = st.top() + 1;
        st.push(i);
    }
    st = stack<int>();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] >= v[i])
            st.pop();
        if (st.empty())
            next[i] = n - 1;
        else
            next[i] = st.top() - 1;
        st.push(i);
    }
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        area = max(area, v[i] * (next[i] - prev[i] + 1));
    }
    return area;
}
int main()
{
    vector<vector<char>> v{{'1', '0'}, {'1', '0'}};
    vector<vector<int>> total(v.size(), vector<int>(v[0].size(), 0));
    int m = v.size(), n = v[0].size();
    for (int i = 0; i < n; i++)

    {
        if (v[0][i] == '1')
            total[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '1')
            {
                total[i][j] = 1 + total[i - 1][j];
                cout << total[i][j] << " ";
            }
        }
        cout << endl;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = max(ans, histogram(total[i]));
    cout << ans;
    return 0;
}