#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{5, 1, 3, 8, 7, 2, 6, 9};
    int k = 14;
    unordered_set<int> st;
    for (auto x : v)
    {
        if (st.count(k - x) > 0)
        {
            cout << x << " " << k - x << endl;
        }
        else
            st.insert(x);
    }

    // IF ARRAY IS ALREADY SORTED WE USE TWO POINTER APPROACH
    sort(v.begin(), v.end());
    int j = v.size() - 1, i = 0;
    while (i < j)
    {
        if (v[i] + v[j] == k)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] > k)
            j--;
        else
            i++;
    }

    // TIME : O(NLogN) //If not sorted
    // SPACE: O(1)

    // NOW CALCULATE IT FOR ARR[J]-ARR[I]==K IF ARRAY IS SORTED
    cout << endl;
    vector<int> arr{-3, 0, 1, 3, 6, 8, 11, 14, 18, 23};
    k = 5;
    j = 1;
    i = 0;
    while (i < arr.size() - 1 && j < arr.size())
    {
        if (arr[j] - arr[i] == k)
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j++;
        }
        else if (arr[i] + arr[j] > k)
            i++;
        else
            j++;
    }
    return 0;
}
