#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

vector<vector<int>> floyd(const vector<vector<int>>& adj_ori) {
    vector<vector<int>> adj(adj_ori);
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
        adj[i][a] = min(adj[i][a], adj[i][b]+adj[b][a]);
        adj[i][b] = min(adj[i][b], adj[i][a]+adj[a][b]);
        adj[a][i] = min(adj[a][i], adj[a][b]+adj[b][i]);
        adj[b][i] = min(adj[b][i], adj[b][a]+adj[a][i]);
    }
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            adj[i][j] = min(adj[i][j], adj[i][a]+adj[a][j]);
            adj[i][j] = min(adj[i][j], adj[i][b]+adj[b][j]);
        }
    }
}

void Solve() {
    int v, m, n;
    cin >> v >> m >> n;

    vector<vector<int>> adj(v, vector<int>(v, kInf));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[a][b], c);
    }

    auto dist = floyd(adj);
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (dist[a][b] > c)
            InsertEdge(&dist, a, b, c);
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
