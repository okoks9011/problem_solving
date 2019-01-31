#include <iostream>
#include <vector>
#include <deque>
#include <set>

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
    set<int> reachable{1};
    while (!reachable.empty()) {
        auto it = reachable.begin();
        int cur = *it;
        reachable.erase(it);
        visited[cur] = true;
        for (auto& adj : g[cur]) {
            if (!visited[adj])
                reachable.emplace(adj);
        }
        cout << cur << " ";
    }
    cout << endl;
}
