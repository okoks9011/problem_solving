#include <iostream>
#include <vector>

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

    vector<vector<int>> delay(v, vector<int>(v));
    for (int k = 0; k < v; ++k) {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                auto cost = adj[i][j] + delay[i][j];

                auto max_delay = max(max(delay[i][k], delay[k][j]), t[k]);
                auto new_cost = adj[i][k] + adj[k][j] + max_delay;
                if (new_cost < cost) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    delay[i][j] = max_delay;
                }
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
        cout << adj[s][t] + delay[s][t] << endl;
    }
}
