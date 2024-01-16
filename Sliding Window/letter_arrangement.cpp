// GIVEN A LIST OF NUMBERS RETURN THE KTH SMALLEST COMINBINATION FORMED USING ONLY THE ALPHABETS
// EXAMPLE: [1,5,7] , k = 5 -> 1,5,7,11,15,17,51,55,57 OUTPUT=15

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v{'1', '5', '7'};
    int n = v.size(), k = 5, i = 0;
    string a = "";
    queue<string> q;
    for (int i = 0; i < n; i++) q.push(string(1, v[i]));
    while (k--){
        a = q.front();
        q.pop();
        for (int j = 0; j < n; j++){
            string m = a + v[j];
            q.push(m);
        }
    }
    cout << a;
    return 0;
}
