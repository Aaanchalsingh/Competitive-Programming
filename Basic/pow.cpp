#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++) ans*=a;
    return ans;
}
//TC == O(N)
//SC == O(1)

int recursive_power(int a, int b){
    if(b==0) return 1;
    else return a*recursive_power(a,b-1);
}
//TC == O(N)
//SC == O(N)

int Improved_Recursive_power(int a, int b){
    if(b==0) return 1;
    int t=Improved_Recursive_power(a,b/2);
    if(!(b&1)) return t*t;
    else return t*t*a;
}
//TC == O(LogN)
//SC == O(LogN)


//BINARY EXPONENTIATION
int power_logn(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans *= a;
        a *= a;       //This is used to move through
        b = b >> 1;  //binary number 101010 so to move we
                    //need take its square
    }
    return ans;
}
//TC == O(LogN)
//SC == O(1)

int main()
{
    int a = 2, b = 4;
    cout << power(a, b)<<endl;
    cout << power_logn(a, b)<<endl;
    cout << recursive_power(a, b)<<endl;
    cout << Improved_Recursive_power(a, b)<<endl;
    return 0;
}