#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int maxsum;
    int prefix;
    int suffix;
    int totalsum;
    Node()
    {
        maxsum = 0;
        prefix = 0;
        suffix = 0;
        totalsum = 0;
    }
    int BuildTree(vector<int> v, vector<Node> &tree, int i, int start, int end)
    {
        if (start == end)
        {
            maxsum = v[i];
            prefix = v[i];
            suffix = v[i];
            totalsum = v[i];
            return;
        }
        int mid = (start + end) / 2;
        BuildTree(v, tree, 2 * i, start, mid);
        BuildTree(v, tree, 2 * i + 1, mid + 1, end);
        l = tree[2 * i];
        r = tree[2 * i + 1];
        maxsum = max({l, r, l.suffix + r.prefix});
        prefix = max(l.totalsum + r.prefix, l.prefix);
        suffix = max(r.suffix, r.totalsum + l.suffix);
        totalsum = l.totalsum + r.totalsum;
        return;
    }
    int Max_Subarray_Sum(vector<int> &tree, int start, int end, int i, int qstart, int qend)
    {
        if (start > qend || end < qstart)
            return 0;
        else if (start >= qstart and end <= qend)
        {
            return tree[i];
        }
        else
        {
            int mid = (start + end) / 2;
            int left = Max_Subarray_Sum(tree, start, mid, 2 * i, qstart, qend);
            int Right = Max_Subarray_Sum(tree, mid + 1, end, 2 * i + 1, qstart, qend);
            return max({left, Right, left + Right});
        }
    }
} l, r;
void update(vector<int> &tree, int start, int end, int i, int index, int key)
{
    if (index < start || index > end)
        return;
    if (start == end)
    {
        tree[index] = key;
        return;
    }
    else
    {
        int mid = (start + end) / 2;
        update(tree, start, mid, 2 * i, index, key);
        update(tree, mid + 1, end, 2 * i + 1, index, key);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        return;
    }
}
int main()
{
    Node root;
    vector<int> v{5, -1, -1, -1, 6, -1};
    int n = v.size();
    vector<int> tree(4 * n + 1, 0);
    root.BuildTree(v, tree, 1, 0, n - 1);
    for (auto x : tree)
        cout << x << " ";
    cout << endl;
    cout << root.Max_Subarray_Sum(tree, 0, n - 1, 1, 0, n - 1) << endl;
    return 0;
}