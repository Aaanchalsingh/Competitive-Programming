#include <bits/stdc++.h>
using namespace std;
// To convert Decimal To Binary take LCM and Store Remainder in String
// s+=p takes more time than s.append(p) which does it in o(1) time
// To find for negative numbers like -10 first find the binary of 10 and take its 2s comple
int main()
{
    int x = 10;
    string binary = "";
    while (x != 0)
    {
        int rem = x % 2;
        binary += to_string(rem);
        x /= 2;
    }
    reverse(binary.begin(), binary.end());
    cout << binary << endl;
    cout << ~5 << endl; // This will give -(x+1)
    // This doesnot simply imply to unsigned int
    cout << ~(~5) << endl;
    cout << (5<<2) << endl;//   a<<2^b
    cout << (5>>2) << endl;//   a>>2^b
    return 0;
}