// ALL POSSIBLE COMBINATION WITH GIVEN NUMBER WHEN TYPES  IN A PHONE KEYPAD
#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> v, string input, int i, string output)
{
    if (i == input.size())
    {
        cout << output << " ";
        return;
    }
    int a = input[i] - '0';
    if (a == 0)
        return solve(v, input, i + 1, output);
    for (auto x : v[a])
    {
        solve(v, input, i + 1, output + x);
    }
}
int main()
{
    string key = "23";
    vector<string> v{"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    solve(v, key, 0, "");

    return 0;
}