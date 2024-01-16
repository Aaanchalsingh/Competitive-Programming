// MONOTONIC STACK FLAVOURS

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{1, 6, 4, 12, 3, 8};
    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> st;

    // 1. NEAREST SMALLEST ELEMENT IN THE ARRAY ON THE LEFT

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= v[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(v[i]);
    }
    cout << "NEAREST SMALLEST ELEMENT IN THE ARRAY ON THE LEFT" << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    ans = vector<int>(n, -1);
    st = stack<int>();

    // 2. NEAREST SMALLEST ELEMENT IN THE ARRAY ON THE RIGHT

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= v[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(v[i]);
    }
    cout << "NEAREST SMALLEST ELEMENT IN THE ARRAY ON THE RIGHT" << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    ans = vector<int>(n, -1);
    st = stack<int>();

    // 2. NEAREST LARGEST ELEMENT IN THE ARRAY ON THE LEFT

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= v[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(v[i]);
    }

    cout << "NEAREST LARGEST ELEMENT IN THE ARRAY ON THE LEFT" << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    ans = vector<int>(n, -1);
    st = stack<int>();

    // 4. NEAREST LARGEST ELEMENT IN THE ARRAY ON THE RIGHT

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(v[i]);
    }
    cout << "NEAREST LARGEST ELEMENT IN THE ARRAY ON THE RIGHT" << endl;
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
