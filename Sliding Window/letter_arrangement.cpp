// GIVEN A LIST OF NUMBERS RETURN THE KTH SMALLEST COMINBINATION FORMED USING ONLY THE ALPHABETS
// EXAMPLE: [1,5,7] , k = 5 -> 1,5,7,11,15,17,51,55,57 OUTPUT=15
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> v{'1', '5', '7'};
    int n = v.size();
    queue<char> q;
    for (auto x : v)
        q.push(x);

    return 0;
}