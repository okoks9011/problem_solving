#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

int main() {
    int v, e;
    cin >> v >> e;

    vector<int> t(v);
    for (auto& ti : t)
        cin >> ti;

    vector<vector<int>> adj(v, vector<int>(v, kInf));
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for (int i = 0; i < v; ++i)
        adj[i][i] = 0;

    vector<pair<int, int>> order;
    for (int i = 0; i < v; ++i)
        order.emplace_back(t[i], i);
    sort(order.begin(), order.end());

    vector<vector<int>> worst(adj);
    for (int k = 0; k < v; ++k) {
        auto w = order[k].second;
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][w]+adj[w][j]);
                worst[i][j] = min(worst[i][j], adj[i][w]+adj[w][j]+t[w]);
            }
        }
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        cout << worst[s][t] << endl;
    }
}
