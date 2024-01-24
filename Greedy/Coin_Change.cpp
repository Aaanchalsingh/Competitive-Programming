// INDIAN COIN CHANGE
// REACH A TARGET WITH MINIMUM NO. OF COINS
#include <bits/stdc++.h>
using namespace std;
int MiniCoins(vector<int> v, int target)
{
    vector<int>::iterator it = upper_bound(v.begin(), v.end(), target);
    int val = it - v.begin();
    int coins = 0, i = val - 1;
    while (target > 0 && i >= 0)
    {
        if (v[i] <= target)
        {
            coins++;
            target -= v[i];
        }
        else
            i--;
    }
    return coins;
}
int DP_Brute(vector<int> v, int target, int i)
{
    if (i <= v.size())
        return 1e9;
    if (target <= 0)
        return 1e9;
    int nottake = DP_Brute(v, target, i + 1);
    int take = 1e9;
    if (target - v[i] >= 0)
        take = 1 + DP_Brute(v, target - v[i], i);
    return min(take, nottake);
}
int main()
{
    vector<int> v{1, 2, 5, 10, 20, 50, 100, 200, 500};
    int target = 458;
    cout << MiniCoins(v, target) << endl;
    cout << DP_Brute(v, target, 0) << endl;
    return 0;
}