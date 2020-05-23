#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>


using namespace std;


struct RMMQ {
    vector<pair<int, int>> tree;
    int n = 0;

    RMMQ(const vector<int>& v) {
        n = v.size();
        tree = vector<pair<int, int>>(n*4);
        init(1, 0, n-1, v);
    }

    void init(int cur, int left_node, int right_node,
              const vector<int>& v) {
        if (left_node == right_node) {
            tree[cur] = {v[left_node], v[left_node]};
            return;
        }

        int left_child = 2 * cur;
        int right_child = 2 * cur + 1;
        int mid = (left_node + right_node) / 2;
        init(left_child, left_node, mid, v);
        init(right_child, mid+1, right_node, v);

        int min_v = min(tree[left_child].first, tree[right_child].first);
        int max_v = max(tree[left_child].second, tree[right_child].second);
        tree[cur] = {min_v, max_v};
    }

    pair<int, int> query(int cur, int left, int right, int left_node, int right_node) {
        if (right < left_node || right_node < left)
            return {numeric_limits<int>::max(), numeric_limits<int>::min()};
        if (left <= left_node && right_node <= right)
            return tree[cur];

        int left_child = 2 * cur;
        int right_child = 2 * cur + 1;
        int mid = (left_node + right_node) / 2;
        auto left_result = query(left_child, left, right, left_node, mid);
        auto right_result = query(right_child, left, right, mid+1, right_node);
        return {min(left_result.first, right_result.first),
                max(left_result.second, right_result.second)};
    }

    int most_diff(int left, int right) {
        auto p = query(1, left, right, 0, n-1);
        return p.second - p.first;
    }
};


void Solve() {
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (auto& hi : h)
        cin >> hi;

    auto rmmq = RMMQ(h);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << rmmq.most_diff(a, b) << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
