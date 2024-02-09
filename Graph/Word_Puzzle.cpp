#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
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
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void addWord(string word)
    {
        Node *temp = root;
        for (auto ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                Node *child = new Node(ch);
                temp->children[ch] = child;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }

    bool search(int i, int j, vector<vector<char>> &board, vector<char> &output, set<string> &st, Node *current)
    {
        if (current->isTerminal)
        {
            string word(output.begin(), output.end());
            st.insert(word);
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '\0' || current->children.count(board[i][j]) == 0)
            return false;

        char ch = board[i][j];
        output.push_back(ch);
        board[i][j] = '\0';

        bool found = search(i + 1, j, board, output, st, current->children[ch]) ||
                     search(i - 1, j, board, output, st, current->children[ch]) ||
                     search(i, j + 1, board, output, st, current->children[ch]) ||
                     search(i, j - 1, board, output, st, current->children[ch]) ||
                     search(i + 1, j - 1, board, output, st, current->children[ch]) ||
                     search(i - 1, j + 1, board, output, st, current->children[ch]) ||
                     search(i + 1, j + 1, board, output, st, current->children[ch]) ||
                     search(i - 1, j - 1, board, output, st, current->children[ch]);

        output.pop_back();
        board[i][j] = ch;

        return found;
    }

    void searchWords(vector<vector<char>> &board, set<string> &st)
    {
        vector<char> output;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                search(i, j, board, output, st, root);
            }
        }
    }
};

int main()
{
    Trie t;
    vector<string> words{"GEEKS", "FOR", "QUIZ", "GO"};
    vector<vector<char>> board{{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};

    for (auto w : words)
    {
        t.addWord(w);
    }

    set<string> str;
    t.searchWords(board, str);

    for (auto x : str)
    {
        cout << x << " ";
    }
    return 0;
}
