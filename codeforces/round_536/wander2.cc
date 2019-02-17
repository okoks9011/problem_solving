#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    deque<bool> visited(n+1);
    priority_queue<int, vector<int>, greater<int>> reachable;
    reachable.push(1);
    visited[1] = true;
    while (!reachable.empty()) {
        auto cur = reachable.top();
        reachable.pop();
        for (auto& adj : g[cur]) {
            if (!visited[adj]) {
                reachable.push(adj);
                visited[adj] = true;
            }
        }
        cout << cur << " ";
    }
    cout << endl;
}
