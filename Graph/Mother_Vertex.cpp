#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for (auto nextNode : adj[node]) {
        if (!vis[nextNode]) {
            dfs(nextNode, vis, adj);
        }
    }
}

int findMotherVertex(int N, vector<int> adj[]) {
    vector<int> vis(N, 0);
    int motherVertex = -1;

    // Perform DFS to find a potential mother vertex
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj);
            motherVertex = i;
        }
    }

    // Check if the potential mother vertex can reach all other vertices
    fill(vis.begin(), vis.end(), 0);
    dfs(motherVertex, vis, adj);
    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            return -1; // If the potential mother vertex cannot reach all vertices, return -1
        }
    }

    return motherVertex;
}

int main() {
    int N = 5;
    vector<int> adj[N];

    // Sample graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(4);

    int motherVertex = findMotherVertex(N, adj);

    if (motherVertex != -1) {
        cout << "Mother vertex is: " << motherVertex << endl;
    } else {
        cout << "No mother vertex found" << endl;
    }

    return 0;
}
