#include <bits/stdc++.h>
using namespace std;
int countMatchingSubarrays(vector<int> &v, vector<int> &p)
{
    int k = p.size(), n = v.size(), j = 0, count = 0; /*[1,4,4,1,3,2,5,3], pattern = [1,0,-1]*/
    for (int i = 0; i < k; i++)
    {
        if (p[j] == 1)
        {
            if (v[i] < v[i + 1])
            {
                j++;
            }
        }
        else if (p[j] == 0)
        {
            if (v[i] == v[i + 1])
            {
                j++;
            }
        }
        else
        {
            if (v[i] > v[i + 1])
            {
                j++;
            }
        }
    }
    if (j == k)
        count++;
    j = 0;
    int i = 1;
    while (i < n - 1)
    {
        if (p[j] == 1)
        {
            if (v[i] < v[i + 1])
            {
                j++;
            }
            else
            {
                i++;
                j = 0;
            }
        }
        else if (p[j] == 0)
        {
            if (v[i] == v[i + 1])
            {
                j++;
            }
            else
            {
                i++;
                j = 0;
            }
        }
        else
        {
            if (v[i] > v[i + 1])
            {
                j++;
            }
            else
            {
                i++;
                j = 0;
            }
        }
        if (j == p.size())
        {
            count++;
            j = 0;
        }
    }
}
int main()
{

    return 0;
}