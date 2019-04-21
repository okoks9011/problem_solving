#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

enum Color {
    kWhite,
    kGray,
    kBlack,
};

pair<int, int> ExtractEdge(const string& w1, const string& w2) {
    for (int i = 0; i < w1.size() && i < w2.size(); ++i) {
        if (w1[i] != w2[i])
            return {w1[i]-'a', w2[i]-'a'};
    }
    return {-1, -1};
}

bool dfs(int u, const vector<vector<int>>& g,
         vector<Color>* colors_ptr, vector<int>* order_ptr) {
    auto& colors = *colors_ptr;
    if (colors[u] == kGray)
        return false;
    if (colors[u] == kBlack)
        return true;

    colors[u] = kGray;
    for (auto& v : g[u]) {
        if (!dfs(v, g, colors_ptr, order_ptr))
            return false;
    }
    colors[u] = kBlack;

    auto& order = *order_ptr;
    order.emplace_back(u);
    return true;
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

    vector<Color> colors(26, kWhite);
    vector<int> order;
    for (int i = 0; i < 26; ++i) {
        if (!dfs(i, g, &colors, &order)) {
            cout << "INVALID HYPOTHESIS" << endl;
            return;
        }
    }

    reverse(order.begin(), order.end());
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
