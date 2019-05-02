#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

vector<vector<int>> floyd(const vector<vector<int>>& adj_raw) {
    vector<vector<int>> adj(adj_raw);
    int v = adj.size();

    for (int i = 0; i < v; ++i)
        adj[i][i] = 0;

    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
        }
    }
    return adj;
}

void InsertEdge(vector<vector<int>>* adj_ptr,
                int a, int b, int c) {
    auto& adj = *adj_ptr;
    int v = adj.size();

    adj[a][b] = c;
    adj[b][a] = c;

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            auto new_cost = min(adj[i][a]+adj[a][b]+adj[b][j], adj[i][b]+adj[b][a]+adj[a][j]);
            adj[i][j] = min(adj[i][j], new_cost);
        }
    }
}

void Solve() {
    int v, m, n;
    cin >> v >> m >> n;

    vector<vector<int>> adj_raw(v, vector<int>(v, kInf));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_raw[a][b] = min(adj_raw[a][b], c);
        adj_raw[b][a] = min(adj_raw[a][b], c);
    }

    auto adj = floyd(adj_raw);
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (adj[a][b] > c)
            InsertEdge(&adj, a, b, c);
        else
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
