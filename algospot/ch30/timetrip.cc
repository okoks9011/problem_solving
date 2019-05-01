#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

vector<vector<char>> floyd(const vector<vector<pair<int, int>>>& adj) {
    int g = adj.size();
    vector<vector<char>> reach(g, vector<char>(g));
    for (int i = 0; i < g; ++i) {
        for (auto& next : adj[i])
            reach[i][next.first] = true;
        reach[i][i] = true;
    }

    for (int k = 0; k < g; ++k) {
        for (int i = 0; i < g; ++i) {
            for (int j = 0; j < g; ++j)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
        }
    }
    return reach;
}

int bellmanford(const vector<vector<pair<int, int>>>& adj,
                const vector<vector<char>>& reach) {
    int g = adj.size();
    vector<int> upper(g, kInf);
    upper[0] = 0;

    for (int i = 0; i < g-1; ++i) {
        for (int here = 0; here < g; ++here) {
            for (auto& next : adj[here]) {
                auto there = next.first;
                auto new_cost = upper[here] + next.second;
                upper[there] = min(upper[there], new_cost);
            }
        }
    }

    for (int here = 0; here < g; ++here) {
        for (auto& next : adj[here]) {
            auto there = next.first;
            auto new_cost = upper[here] + next.second;
            if (upper[there] > new_cost && reach[0][there] && reach[there][1])
                return -kInf;
        }
    }
    return upper[1];
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

    auto reach = floyd(adj);
    auto shortest = bellmanford(adj, reach);
    if (shortest >= kInf/2) {
        cout << "UNREACHABLE" << endl;
        return;
    } else if (shortest <= -kInf/2) {
        cout << "INFINITY";
    } else {
        cout << shortest;
    }
    cout << " ";

    for (auto& edges : adj) {
        for (auto& p : edges)
            p.second *= -1;
    }

    auto longest = bellmanford(adj, reach);
    if (longest <= -kInf/2) {
        cout << "INFINITY" << endl;
    } else {
        cout << -longest << endl;
    }
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
