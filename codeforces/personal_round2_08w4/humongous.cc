#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define ll long long


using namespace std;


pair<ll, ll> dfs(int cur, int parent,
       const vector<pair<int, int>>& ranges, const vector<vector<int>>& adjs) {
    int n = adjs.size();
    if (cur < 0 || cur >= n)
        return {0LL, 0LL};

    int min_v = ranges[cur].first;
    int max_v = ranges[cur].second;
    ll min_result = 0LL;
    ll max_result = 0LL;
    for (auto& adj : adjs[cur]) {
        if (adj == parent)
            continue;

        auto adj_result = dfs(adj, cur, ranges, adjs);
        min_result += max(abs(min_v-ranges[adj].first)+adj_result.first,
                         abs(min_v-ranges[adj].second)+adj_result.second);
        max_result += max(abs(max_v-ranges[adj].first)+adj_result.first,
                         abs(max_v-ranges[adj].second)+adj_result.second);
    }
    return {min_result, max_result};
}

void Solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ranges(n);
    for (auto& p : ranges)
        cin >> p.first >> p.second;

    vector<vector<int>> adjs(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjs[u].emplace_back(v);
        adjs[v].emplace_back(u);
    }

    auto result = dfs(0, -1, ranges, adjs);
    cout << max(result.first, result.second) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        Solve();
    }
}
