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
int main()
{
    Node *root = build();
    printTree(root);
    cout << endl;
    Levelorder(root);

    return 0;
}