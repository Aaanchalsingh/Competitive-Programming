#include <iostream>
#include <vector>
using namespace std;

bool checkHamiltonian(int node, int count, int n, vector<int> &vis, vector<int> adj[])
{
    if (count == n)
        return true;

    vis[node] = 1;
    for (auto nodes : adj[node])
    {
        if (!vis[nodes])
        {
            if (checkHamiltonian(nodes, count + 1, n, vis, adj))
                return true;
        }
    }

    vis[node] = 0; // for reusing visited vector
    return false;
}

bool check(int N, int M, vector<vector<int>> Edges)
{
    vector<int> adj[N + 1];
    for (auto vec : Edges)
    {
        int u = vec[0], v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (checkHamiltonian(i, 1, N, vis, adj))
            return true;
    }

    return false;
}

int main()
{
    int N = 4, M = 4;
    vector<vector<int>> Edges = {{1, 2}, {2, 3}, {3, 4}, {2, 4}};
    if (check(N, M, Edges))
    {
        cout << "Graph contains a Hamiltonian cycle." << endl;
    }
    else
    {
        cout << "Graph does not contain a Hamiltonian cycle." << endl;
    }
    return 0;
}
