#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, vector<bool> &vis, vector<vector<int>> graph, string &output) {
    vis[i] = true;
    for (auto child : graph[i]) {
        if (!vis[child])
            dfs(child, vis, graph, output);
    }
    char temp = i + 'a';
    output = temp + output;
    return;
}

string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adj(k + 1);
    string output = "";
    for (int i = 0; i < n - 1; i++) {

        string s1 = dict[i];
        string s2 = dict[i + 1];

        for (int j = 0; j < min(s1.size(), s2.size()); j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<bool> vis(k + 1, false);
    for (int i = 0; i < k; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, output);
        }
    }
    return output;
}

int main() {
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = sizeof(dict) / sizeof(dict[0]);
    int k = 4;
    cout << "Lexicographically sorted order of characters is: " << findOrder(dict, n, k) << endl;
    return 0;
}
