#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{6, 1, 4, 8, 9, 3, 2, 1, 10, 12, 13};
    int n = v.size(), c = 0, ans = 1;
    unordered_set<int> st(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int key = v[i];
        c = 1;
        if (!st.count(key - 1))
        {
            while (st.count(key + 1))
            {
                c++;
                key++;
            }
            ans = max(ans, c);
        }
    }
    //TIME : O(N)
    //SPACE: O(N)
    if (n == 0)
        return 0;
    cout << ans;

    return 0;
}