#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>

using namespace std;

struct Node {
    bool is_leaf = false;
    int word_cnt = 0;
    vector<shared_ptr<Node>> children = vector<shared_ptr<Node>>(26);
};

void InsertNode(shared_ptr<Node> head, const string& s) {
    auto cur = head;

    for (const auto& si : s) {
        ++(cur->word_cnt);
        auto& next = cur->children[si-'A'];
        if (!next)
            next = make_shared<Node>();
        cur = next;
    }
    ++(cur->word_cnt);
    cur->is_leaf = true;
}

void PrintNode(shared_ptr<Node> head) {
    cout << head->word_cnt << endl;
    for (auto& child : head->children) {
        if (child)
            PrintNode(child);
    }
}

int CountRemain(shared_ptr<Node> cur) {
    if (!cur)
        return 0;
    if (cur->word_cnt == 1)
        return 1;

    int cur_remain = 0;
    if (cur->is_leaf)
        ++cur_remain;
    for (auto& child : cur->children)
        cur_remain += CountRemain(child);

    if (cur_remain >= 2)
        cur_remain -= 2;
    return cur_remain;
}

void Solve() {
    int n;
    cin >> n;

    auto head = make_shared<Node>();
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        InsertNode(head, {tmp.rbegin(), tmp.rend()});
    }

    int result = n;
    for (auto& child : head->children)
        result -= CountRemain(child);

    cout << result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
