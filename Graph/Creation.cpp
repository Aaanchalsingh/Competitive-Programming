#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<vector<int>> adj;
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
};
int main()
{
    Graph g(4);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 2);

    g.printEdges();

    return 0;
}