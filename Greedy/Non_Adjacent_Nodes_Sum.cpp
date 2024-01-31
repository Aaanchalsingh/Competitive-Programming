// SUM OF NON ADJACENT NODES
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
} *root;
pair<int, int> solve(Node *root)
{
    if (!root)
    {
        pair<int, int> c;
        c.first = 0;
        c.second = 0;
        return c;
    }
    pair<int, int> x = solve(root->left);
    pair<int, int> y = solve(root->right);
    pair<int, int> c;
    c.first = x.second + y.second + root->data;
    c.second = max(x.first, x.second) + max(y.first, y.second);
    return c;
}
int main()
{
    pair<int, int> ans = solve(root);
    cout << max(ans.first, ans.second);
    return 0;
}