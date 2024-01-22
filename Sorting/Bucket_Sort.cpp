// BUCKET SORT
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node() {}
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert(node **bins, int data)
{
    node *ptr = new node(data);
    ptr->next = NULL;
    if (bins[data] == NULL)
    {
        bins[data] = ptr;
    }
    else
    {
        node *p = bins[data];
        while (p->next)
        {
            p = p->next;
        }

        p->next = ptr;
    }
}
int Delete(node **bin, int data)
{
    node *ptr = bin[data];
    bin[data] = bin[data]->next;
    int x = ptr->data;
    delete ptr;
    return x;
}

void Bucket_Sort(vector<int> &A, int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    node **bin = new node *[max + 1];
    for (int i = 0; i <= max; i++)
        bin[i] = NULL;
    for (int i = 0; i < n; i++)
        insert(bin, A[i]);
    int j = 0;
    int i = 0;
    while (i <= max)
    {
        while (bin[i] != NULL)
        {
            A[j++] = Delete(bin, i);
        }
        i++;
    }
    delete[] bin;
}
int main()
{
    vector<int> v{390, 380, 350, 360, 340, 300, 220, 118, 23};
    unordered_map<int, string> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp.insert({v[i], "Student " + to_string(i)});
    }
    Bucket_Sort(v, v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << mp[v[i]] << " " << v[i]+1 << endl;
    }
    return 0;
}