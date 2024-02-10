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
int Minimum_Element_In_Range(vector<int> &tree, int start, int end, int i, int qstart, int qend)
{
    if (start > qend || end < qstart)
        return 1e9;
    else if (start >= qstart and end <= qend)
    {
        return tree[i];
    }
    else
    {
        int mid = (start + end) / 2;
        int left = Minimum_Element_In_Range(tree, start, mid, 2 * i, qstart, qend);
        int Right = Minimum_Element_In_Range(tree, mid + 1, end, 2 * i + 1, qstart, qend);
        return min(left, Right);
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
    cout << Minimum_Element_In_Range(tree, 0, n - 1, 1, 3, 5) << endl;
    return 0;
}