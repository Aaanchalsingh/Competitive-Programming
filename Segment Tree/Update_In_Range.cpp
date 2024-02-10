#include <bits/stdc++.h>
using namespace std;
void BuildTree(vector<int> v, vector<int> &tree, int i, int start, int end)
{
    if (start == end)
    {
        tree[i] = v[end];
        return;
    }
    int mid = (start + end) / 2;
    BuildTree(v, tree, 2 * i, start, mid);
    BuildTree(v, tree, 2 * i + 1, mid + 1, end);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    return;
}

void Update_Range(vector<int> &tree, int start, int end, int i, int sindex, int endindex, int key)
{
    if (endindex < start || sindex > end)
        return;
    if (start == end)
    {
        tree[i] += key;
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        Update_Range(tree, start, mid, 2 * i, sindex, endindex, key);
        Update_Range(tree, mid + 1, end, 2 * i + 1, sindex, endindex, key);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        return;
    }
}
int main()
{
    vector<int> v{3, 5, 1, 6, 2, 7, 4};
    int n = v.size();
    vector<int> tree(4 * n + 1, 0);
    BuildTree(v, tree, 1, 0, n - 1);
    for (auto x : tree)
        cout << x << " ";
    cout << endl;
    Update_Range(tree, 0, n, 1, 4, 6, 5);
    for (auto x : tree)
        cout << x << " ";
    return 0;
}