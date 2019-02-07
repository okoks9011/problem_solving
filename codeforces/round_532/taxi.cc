#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Edge {
    int f = 0;
    int t = 0;
    int w = 0;
    int ori_idx = 0;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

enum Color {
    kWhite,
    kGray,
    kBlack,
};

bool dfs(vector<vector<Edge>>& g, int cur, vector<Color>* color_ptr, vector<int>* order_ptr, int k) {
    auto& color = *color_ptr;
    if (color[cur] == kBlack)
        return false;
    if (color[cur] == kGray)
        return true;

    color[cur] = kGray;
    for (auto& e : g[cur]) {
        if (e.w <= k)
            continue;
        if (dfs(g, e.t, color_ptr, order_ptr, k))
            return true;
    }
    color[cur] = kBlack;

    auto& order = *order_ptr;
    order.emplace_back(cur);

    return false;
};

bool IsCycle(vector<vector<Edge>>& g, int n, int k) {
    vector<Color> color(n+1, kWhite);
    vector<int> order;
    for (int i = 1; i <= n; ++i) {
        if (dfs(g, i, &color, &order, k))
            return true;
    }
    return false;
}

ostream& operator<<(ostream& os, Edge& e) {
    os << "idx: " << e.ori_idx;
    os << " from: " << e.f;
    os << " to: " << e.t;
    os << " c: " << e.w;
    return os;
}

vector<int> TopologicalSort(vector<vector<Edge>>& g, int n, int k) {
    vector<Color> color(n+1, kWhite);
    vector<int> order;
    for (int i = 1; i <= n; ++i)
        dfs(g, i, &color, &order, k);

    return {order.rbegin(), order.rend()};
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n+1);
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        Edge e;
        e.ori_idx = i+1;
        cin >> e.t >> e.f >> e.w;
        g[e.f].emplace_back(e);
        edges[i] = e;
    }

    sort(edges.begin(), edges.end());

    int left = 0;
    int right = m-1;
    int k_idx = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (IsCycle(g, n, edges[mid].w)) {
            left = mid + 1;
        } else {
            k_idx = mid;
            right = mid - 1;
        }
    }
    int k = edges[k_idx].w;

    auto t_sorted = TopologicalSort(g, n, k);
    unordered_set<int> selected;
    vector<int> order(n+1);
    for (int i = 0; i < t_sorted.size(); ++i) {
        int v = t_sorted[i];
        selected.emplace(v);
        order[v] = i;
    }

    vector<int> result;
    int next = selected.size();
    int i = 0;
    int c = edges[i].w;
    while (c <= k) {
        auto e = edges[i];
        if (selected.find(e.f) == selected.end()) {
            selected.emplace(e.f);
            order[e.f] = next;
            ++next;
        }
        if (selected.find(e.t) == selected.end()) {
            selected.emplace(e.t);
            order[e.t] = next;
            ++next;
        }

        if (order[e.f] >= order[e.t])
            result.emplace_back(e.ori_idx);

        ++i;
        c = edges[i].w;
    }

    cout << k << " " << result.size() << endl;
    for (auto& v : result)
        cout << v << " ";
    cout << endl;
}
