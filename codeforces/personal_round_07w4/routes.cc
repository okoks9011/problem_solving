#include <iostream>
#include <vector>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> adjs(n, vector<char>(n));
    bool direct_rail = false;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u][v] = true;
        adjs[v][u] = true;
    }
    if (adjs[0][n-1] || adjs[n-1][0]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                adjs[i][j] = !adjs[i][j];
        }
    }

    vector<char> visited(n);
    visited[0] = true;
    vector<int> cur;
    cur.emplace_back(0);
    int dist = 1;
    while (!cur.empty()) {
        vector<int> next;
        for (auto& c : cur) {
            for (int i = 0; i < n; ++i) {
                if (!adjs[c][i])
                    continue;
                if (visited[i])
                    continue;
                if (i == n-1) {
                    cout << dist << endl;
                    return 0;
                }
                visited[i] = true;
                next.emplace_back(i);
            }
        }
        ++dist;
        cur = next;
    }
    cout << -1 << endl;
}
