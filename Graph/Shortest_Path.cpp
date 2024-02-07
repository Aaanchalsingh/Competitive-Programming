#include <bits/stdc++.h>
using namespace std;

vector<int> Shortest_Path(vector<vector<pair<int, int>>> &graph, int source){
    int n = graph.size();
    vector<int> ans(n + 1, 1e9);
    queue<pair<int, int>> q;
    q.push({source, 0});
    while (!q.empty())
    {
        int sr = q.front().first;
        int weight = q.front().second;
        ans[sr] = min(ans[sr], weight);
        q.pop();
        for (auto x : graph[sr])
        {
            int dest = x.first;
            int wt = x.second;
            if (wt + weight < ans[dest])
            {
                ans[dest] = wt + weight;
                q.push({dest, ans[dest]});
            }
        }
    }

    return ans;
}
int main()
{
    vector<vector<pair<int, int>>> graph(5);

    graph[1].push_back({4, 5});
    graph[1].push_back({2, 8});

    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});

    graph[3].push_back({2, 7});
    graph[3].push_back({4, 6});

    graph[4].push_back({3, 6});
    graph[4].push_back({1, 5});

    for (int i = 1; i < graph.size(); ++i)
    {
        cout << "Node " << i << ": ";
        for (const auto &edge : graph[i])
        {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
    vector<int> ans;
    int source = 2;
    ans = Shortest_Path(graph, source);

    for (int i = 1; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";
    return 0;
}
