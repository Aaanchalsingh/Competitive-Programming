#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return count(n - 1) + count(n - 2);
}
vector<string> print(int n)
{
    if (n == 1)
    {
        return {"1", "0"};
    }
    vector<string> output;
    vector<string> prev = print(n - 1);
    for (auto x : prev)
    {
        if (prev[x.size() - 1] == "1")
            output.push_back(x + "0");
        else
        {
            output.push_back(x + "1");
            output.push_back(x + "0");
        }
    }
    return output;
}

int main()
{
    int n = 3;
    count(n);
    string s = "";
    vector<string> ans = print(n);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
