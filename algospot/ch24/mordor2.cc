#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>


using namespace std;


struct RMQ {
    vector<int> tree;
    int n = 0;

    RMQ(const vector<int>& v) {
        n = v.size();
        tree = vector<int>(n*4);
        init(1, 0, n-1, v);
    }

    int init(int cur, int left_node, int right_node,
             const vector<int>& v) {
        if (left_node == right_node) {
            tree[cur] = v[left_node];
            return tree[cur];
        }

        int mid = (left_node + right_node) / 2;
        int left_min = init(2*cur, left_node, mid, v);
        int right_min = init(2*cur+1, mid+1, right_node, v);

        tree[cur] = min(left_min, right_min);
        return tree[cur];
    }

    int query_inner(int cur, int left, int right, int left_node, int right_node) {
        if (right < left_node || right_node < left)
            return numeric_limits<int>::max();
        if (left <= left_node && right_node <= right)
            return tree[cur];

        int mid = (left_node + right_node) / 2;
        int left_min = query_inner(2*cur, left, right, left_node, mid);
        int right_min = query_inner(2*cur+1, left, right, mid+1, right_node);
        return min(left_min, right_min);
    }

    int query(int left, int right) {
        return query_inner(1, left, right, 0, n-1);
    }
};


void Solve() {
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (auto& hi : h)
        cin >> hi;
    auto range_min = RMQ(h);

    for (auto& hi : h)
        hi = -hi;
    auto range_max = RMQ(h);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int min_v = range_min.query(a, b);
        int max_v = -range_max.query(a, b);
        cout << max_v - min_v << endl;
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
