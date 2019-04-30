#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <limits>
#include <iomanip>

using namespace std;

typedef pair<double, int> Elem;

double dijkstra(const vector<vector<pair<int, double>>>& adj) {
    vector<double> dist(adj.size(), numeric_limits<double>::max());
    dist[0] = 1.0;
    priority_queue<Elem, vector<Elem>, greater<Elem>> min_pq;
    min_pq.emplace(1.0, 0);

    while (!min_pq.empty()) {
        auto cur = min_pq.top();
        min_pq.pop();
        auto cost = cur.first;
        auto here = cur.second;

        if (dist[here] < cost)
            continue;

        for (auto& next : adj[here]) {
            auto there = next.first;
            auto new_cost = next.second * cost;
            if (dist[there] > new_cost) {
                dist[there] = new_cost;
                min_pq.emplace(new_cost, there);
            }
        }
    }

    return dist.back();
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, double>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        double c;
        cin >> c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    cout << dijkstra(adj) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(10) << fixed;

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
