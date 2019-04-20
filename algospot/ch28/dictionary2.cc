#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> ExtractEdge(const string& w1, const string& w2) {
    for (int i = 0; i < w1.size() && i < w2.size(); ++i) {
        if (w1[i] != w2[i])
            return {w1[i]-'a', w2[i]-'a'};
    }
    return {-1, -1};
}

void dfs(int u, const vector<vector<int>>& g,
         vector<int>* visited_ptr, vector<int>* order_ptr) {
    auto& visited = *visited_ptr;
    if (visited[u])
        return;

    visited[u] = 1;
    for (auto& v : g[u])
        dfs(v, g, visited_ptr, order_ptr);

    auto& order = *order_ptr;
    order.emplace_back(u);
}

void Solve() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (auto& w : words)
        cin >> w;

    vector<vector<int>> g(26);
    for (int i = 1; i < n; ++i) {
        auto p = ExtractEdge(words[i-1], words[i]);
        if (p.first != -1)
            g[p.first].emplace_back(p.second);
    }

    vector<int> visited(26);
    vector<int> order;
    for (int i = 0; i < 26; ++i)
        dfs(i, g, &visited, &order);

    reverse(order.begin(), order.end());
    for (int i = 0; i < 26; ++i) {
        int u = order[i];
        for (auto& v : g[u]) {
            int idx_v = find(order.begin(), order.end(), v) - order.begin();
            if (idx_v < i) {
                cout << "INVALID HYPOTHESIS" << endl;
                return;
            }
        }
    }

    for (auto& c : order)
        cout << static_cast<char>(c+'a');
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
