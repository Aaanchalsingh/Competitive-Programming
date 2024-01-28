
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> arr, vector<int> &v, int i)
{
    if (i >= arr.size())
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[i]);
    solve(arr, v, i + 1);
    v.pop_back();
    solve(arr, v, i + 1);
    return;
}
int main()
{
    vector<int> arr{1, 2, 3};
    vector<int> v;
    solve(arr, v, 0);
    return 0;
}