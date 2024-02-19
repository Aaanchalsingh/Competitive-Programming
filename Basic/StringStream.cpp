#include <bits/stdc++.h>
using namespace std;
int main()
{
    stringstream ss;
    string str = "1 China 9";
    ss << str;
    string s;
    getline(ss, s, ' ');
    cout << stoi(s) << endl;
    getline(ss, s, ' ');
    cout << s << endl;
    getline(ss, s, ' ');
    cout << stoi(s) << endl;

    return 0;
}