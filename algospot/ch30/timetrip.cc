#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int kInf = 987654321;

vector<int> bellmanford(const vector<vector<pair<int, int>>>& adj) {
    int g = adj.size();
    vector<int> upper(g, kInf);
    upper[0] = 0;

    bool updated = false;
    for (int i = 0; i < g; ++i) {
        updated = false;
        for (int here = 0; here < g; ++here) {
            for (auto& next : adj[here]) {
                auto there = next.first;
                auto new_cost = upper[here] + next.second;
                if (upper[there] > new_cost) {
                    upper[there] = new_cost;
                    updated = true;
                }
            }
        }
        if (!updated)
            break;
    }

    if (updated)
        return {};
    else
        return upper;
}

void Solve() {
    int g, w;
    cin >> g >> w;

    vector<vector<pair<int, int>>> adj(g);
    for(int i = 0; i < w; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].emplace_back(b, d);
    }

    auto pos = bellmanford(adj);
    if (pos.empty()) {
        cout << "INFINITY";
    } else if (pos[1] < kInf/2) {
        cout << pos[1];
    } else {
        cout << "UNREACHABLE" << endl;
        return;
    }

    for (auto& edges : adj) {
        for (auto& p : edges)
            p.second *= -1;
    }

    auto neg = bellmanford(adj);
    cout << " ";
    if (neg.empty())
        cout << "INFINITY" << endl;
    else
        cout << -1 * neg[1] << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
