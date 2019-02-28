#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct RBCount {
    int red = 0;
    int blue = 0;
    RBCount() = default;
    RBCount(int r, int b) : red(r), blue(b) {}

    RBCount& operator+=(const RBCount& other) {
        red += other.red;
        blue += other.blue;
        return *this;
    }
};

RBCount CalCut(const vector<vector<int>>& g, const vector<int>& color, int cur, int parent,
               const RBCount& total, int* result_ptr) {
    RBCount acc;
    if (color[cur] == 1)
        ++acc.red;
    else if (color[cur] == 2)
        ++acc.blue;

    for (auto& adj : g[cur]) {
        if (adj != parent)
            acc += CalCut(g, color, adj, cur, total, result_ptr);
    }

    auto& result = *result_ptr;
    if ((acc.blue == 0 && acc.red == total.red) ||
        (acc.red == 0 && acc.blue == total.blue))
        ++result;

    return acc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> color(n);
    vector<int> cnt(3);
    for (auto& ci : color) {
        cin >> ci;
        ++cnt[ci];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].emplace_back(v2);
        g[v2].emplace_back(v1);
    }

    int result = 0;
    CalCut(g, color, 0, -1, {cnt[1], cnt[2]}, &result);
    cout << result << endl;
}
