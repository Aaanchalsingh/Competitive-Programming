#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj;
    map<string, vector<string>> mp;

    Graph(int n)
    {
        adj.resize(n + 1);
    }

    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void printEdges()
    {
        int n = adj.size();
        for (int i = 1; i < n; i++)
        {
            cout << "Node " << i << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addStringEdges(string x, string y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void printEdgesString()
    {
        for (const auto &x : mp)
        {
            cout << x.first << " : ";
            for (const auto &v : x.second)
                cout << v << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 2);

    Graph s(4);
    s.addStringEdges("Delhi", "Mumbai");
    s.addStringEdges("Bangalore", "Mumbai");
    s.addStringEdges("Delhi", "Hyderabad");

    g.printEdges();
    s.printEdgesString();

    return 0;
}
