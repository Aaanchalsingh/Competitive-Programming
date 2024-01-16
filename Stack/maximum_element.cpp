// MAXIMUM ELEMENT OF A GIVEN SUBARRAY HAVING LENGTH K
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 3, 2, 4, 6, 1, 4, 2, 7};
    int n = v.size(), k = 3;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[dq.back()] < v[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i <= n; i++)
    {
        cout << v[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && i < n && v[dq.back()] < v[i])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << endl;
    // Another Approach
    multiset<int> st;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        st.insert(v[i]);
    }
    int j = 0;
    for (int i = k; i <= n; i++)
    {
        ans.push_back(*(st.crbegin()));
        if (j < n)
            st.erase(st.find(v[j++]));
        if (i < n)
            st.insert(v[i]);
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}