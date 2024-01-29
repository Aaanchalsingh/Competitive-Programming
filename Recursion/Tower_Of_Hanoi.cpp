#include <bits/stdc++.h>
using namespace std;
void TOH(int n, char source, char helper, char destination)
{
    if (n > 0)
    {
        TOH(n - 1, source, destination, helper); // MOVE PILE FROM SOURCE TO HELPER
        cout << "SHIFT " << source << " TO " << destination << endl;
        TOH(n - 1, helper, source, destination); // MOVE PILE FROM HELPER TO DESTINATION
    }
}
// FOR CALCULATING COUNT
// SINCE WE KNOW THAT TIME TAKEN TO GO FROM A TO C IS SAME AS FROM C TO B
// SO WE ARE RUNNING FOR SINGLE FUNCTION CALL
int TOH_Count(int n, char source, char helper, char destination)
{
    if (n <= 0)
        return 0;
    else
        return 2 * TOH_Count(n - 1, source, destination, helper) + 1;
}
int main()
{
    TOH(3, 'A', 'B', 'C');
    return 0;
}