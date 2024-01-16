#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> mymultiset;
    multiset<int>::iterator itlow, itup;

    for (int i = 1; i < 8; i++)
        mymultiset.insert(i * 10); // 10 20 30 40 50 60 70
    mymultiset.insert(30);
    itlow = mymultiset.lower_bound(35); //       ^
    itup = mymultiset.upper_bound(30);  //             ^

    mymultiset.erase(itlow, itup); // 10 20 50 60 70

    cout << "mymultiset contains:";
    for (multiset<int>::iterator it = mymultiset.begin(); it != mymultiset.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
    return 0;
}