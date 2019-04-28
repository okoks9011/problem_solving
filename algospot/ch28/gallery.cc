#include <iostream>
#include <vector>

using namespace std;

enum Status {
    kNotCovered = 0,
    kCovered,
    kCovering
};

Status dfs(int here, const vector<vector<int>>& adj,
           vector<int>* visited_ptr, int* result_ptr) {
    auto& visited = *visited_ptr;
    visited[here] = 1;

    vector<int> cnt(3);
    for (auto& there : adj[here]) {
        if (visited[there])
            continue;

        auto child_s = dfs(there, adj, visited_ptr, result_ptr);
        ++cnt[child_s];
    }

    if (cnt[kNotCovered]) {
        auto& result = *result_ptr;
        ++result;
        return kCovering;
    }
    if (cnt[kCovering])
        return kCovered;
    return kNotCovered;
}

void Solve() {
    int g, h;
    cin >> g >> h;

    vector<vector<int>> adj(g);
    for (int i = 0; i < h; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> visited(g);
    int result = 0;
    for (int i = 0; i < g; ++i) {
        if (visited[i])
            continue;
        auto s = dfs(i, adj, &visited, &result);
        if (s == kNotCovered)
            ++result;
    }
    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
