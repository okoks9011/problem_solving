#include <vector>

class Solution {
  public:
    void dfs(int v, const vector<vector<int>>& adjs, vector<char>* visited_ptr) {
        auto& visited = *visited_ptr;
        if (visited[v])
            return;
        visited[v] = true;

        for (auto& adj : adjs[v])
            dfs(adj, adjs, visited_ptr);
    }

    int makeConnected(int n, const vector<vector<int>>& conn) {
        if (conn.size() < n-1)
            return -1;

        vector<char> visited(n);
        vector<vector<int>> adjs(n);
        for (int i = 0; i < conn.size(); ++i) {
            int u = conn[i][0];
            int v = conn[i][1];
            adjs[u].emplace_back(v);
            adjs[v].emplace_back(u);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            dfs(i, adjs, &visited);
            ++components;
        }

        return components - 1;
    }
};
