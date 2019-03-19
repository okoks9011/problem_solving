#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node {
    int level = 0;
    shared_ptr<Node> r_child;
    shared_ptr<Node> b_child;
    bool is_leaf = false;
    Node() = default;

    Node(int l) : level(l) {}
};

void InsertNode(shared_ptr<Node> head, const string& s) {
    shared_ptr<Node> cur = head;

    for (auto& si : s) {
        if (si == 'R') {
            if (!cur->r_child) {
                cur->r_child = make_shared<Node>(cur->level+1);
            }
            cur = cur->r_child;
        } else if (si == 'B') {
            if (!cur->b_child) {
                cur->b_child = make_shared<Node>(cur->level+1);
            }
            cur = cur->b_child;
        }
    }
    cur->is_leaf = true;
}

long long CountNode(const shared_ptr<Node>& cur, int n) {
    if (!cur)
        return 0;

    if (cur->is_leaf)
        return 1LL << (n-cur->level);

    return CountNode(cur->r_child, n) + CountNode(cur->b_child, n);
}

long long Solve() {
    int n, p;
    cin >> n >> p;

    auto head = make_shared<Node>(0);
    for (int i = 0; i < p; ++i) {
        string tmp;
        cin >> tmp;
        InsertNode(head, tmp);
    }
    return (1LL << n) - CountNode(head, n);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i + 1 << ": " << s << endl;
    }
}
