#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *build()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node *root = new Node(d);
    root->left = build();
    root->right = build();
    return root;
}
void printTree(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
void Levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        if (temp == NULL)
        {
            q.pop();
            cout << endl;
            if (!q.empty())
                q.push(NULL);
            continue;
        }
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
void Root_To_Leaf(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        for (auto x : v)
            cout << x << " ";
        cout << root->data << endl;
        return;
    }
    v.push_back(root->data);
    Root_To_Leaf(root->left, v);
    Root_To_Leaf(root->right, v);
    v.pop_back();
}
int main()
{
    Node *root = build();
    printTree(root);
    cout << endl;
    Levelorder(root);
    cout << endl;
    vector<int> v;
    Root_To_Leaf(root, v);

    return 0;
}