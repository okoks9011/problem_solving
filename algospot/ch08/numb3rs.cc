#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void Solve() {
    int n, d, p;
    cin >> n >> d >> p;

    vector<vector<int>> g(n, vector<int>(n));
    vector<int> adj(n);
    for (int i = 0; i < n; ++i) {
        int acc = 0;
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            acc += g[i][j];
        }
        adj[i] = acc;
    }

    int t;
    cin >> t;

    vector<int> q(t);
    for (auto& qi : q)
        cin >> qi;

    vector<double> cur(n);
    cur[p] = 1.0;

    for (int i = 0; i < d; ++i) {
        vector<double> next(n);
        for (int v = 0; v < n; ++v) {
            for (int u = 0; u < n; ++u) {
                if (!g[v][u])
                    continue;
                next[u] += cur[v] / adj[v];
            }
        }
        cur = next;
    }

    cout << setprecision(10);
    for (int i = 0; i < t; ++i)
        cout << cur[q[i]] << " ";
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
