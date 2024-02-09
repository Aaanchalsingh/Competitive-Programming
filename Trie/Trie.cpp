/*TRIE is generic tree
prefix tree
Helpful in certain type of problems:
String Searching,Hashing,Graph+trie interview questions
Max XOR PAIR Problem*/

/*Problem- given a dictionary of words,find if a query word is present in the dictionary

1st approach: Linear Search--->O(N*W)
2nd hashmap--->O(1) if word length is constant
3rd TRIE--->O(W)
*/
/*Root node will not store any value
 */
#include <bits/stdc++.h>
using namespace std;
class Node
{

    char data;

public:
    unordered_map<char, Node *> children;
    bool isTerminal;
    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{

    // Data Members
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }
    // Methods
    void addWord(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            // If element is not present in trie
            if (temp->children.count(ch) == 0)
            {
                Node *child = new Node(ch);
                temp->children[ch] = child;
                temp = child;
            }
            // if ch is present in trie
            else
            {
                temp = temp->children[ch];
            }
        }
        // marking last Node as terminal
        temp->isTerminal = true;
    }

    bool search(string query)
    {
        Node *temp = root;
        for (auto ch : query)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else
                return false;
        }
        return (temp->isTerminal);
    }
};
int main()
{
    Trie t;
    string words[] = {"apple", "ape", "batman", "new", "news", "appy"};
    for (auto w : words)
    {
        t.addWord(w);
    }
    string query;
    cin >> query;
    cout << t.search(query);
    return 0;
}