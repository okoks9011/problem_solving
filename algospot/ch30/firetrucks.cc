#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#include <functional>

using namespace std;

typedef pair<int, int> Elem;

int dijkstra(const vector<vector<pair<int, int>>>& adj,
             const vector<int>& station,
             const vector<int>& fire) {
    vector<int> dist(adj.size(), numeric_limits<int>::max());
    priority_queue<Elem, vector<Elem>, greater<Elem>> max_pq;
    for (auto& si : station) {
        dist[si] = 0;
        max_pq.emplace(0, si);
    }

    while (!max_pq.empty()) {
        auto cur = max_pq.top();
        max_pq.pop();

        auto cost = cur.first;
        auto here = cur.second;
        if (dist[here] < cost)
            continue;

        for (auto& next : adj[here]) {
            auto there = next.first;
            auto new_cost = cost + next.second;
            if (dist[there] > new_cost) {
                dist[there] = new_cost;
                max_pq.emplace(new_cost, there);
            }
        }
    }

    int result = 0;
    for (auto& fi : fire)
        result += dist[fi];
    return result;
}

void Solve() {
    int v, e, n, m;
    cin >> v >> e >> n >> m;

    vector<vector<pair<int, int>>> adj(v);
    for (int i = 0; i < e; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a;
        --b;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }

    vector<int> fire(n);
    for (auto& fi : fire) {
        cin >> fi;
        --fi;
    }

    vector<int> station(m);
    for (auto& si : station) {
        cin >> si;
        --si;
    }

    cout << dijkstra(adj, station, fire) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
