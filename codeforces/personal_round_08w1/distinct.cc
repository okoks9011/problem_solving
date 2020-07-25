#include <iostream>
#include <vector>
#include <string>
#include <memory>


using namespace std;


struct SegmentTreeNode {
    int l = 0;
    int r = 0;
    shared_ptr<SegmentTreeNode> left;
    shared_ptr<SegmentTreeNode> right;
    vector<char> alpha;

    SegmentTreeNode(int nl, int nr) : l(nl), r(nr), alpha(26) {}
};


shared_ptr<SegmentTreeNode> CreateNode(int l, int r, const string& s) {
    if (l == r) {
        auto node = make_shared<SegmentTreeNode>(l, r);
        node->alpha[s[l]-'a'] = true;
        return node;
    }

    int mid = (r - l) / 2 + l;
    auto node = make_shared<SegmentTreeNode>(l, r);
    node->left = CreateNode(l, mid, s);
    node->right = CreateNode(mid+1, r, s);
    for (int i = 0; i < 26; ++i)
        node->alpha[i] = node->left->alpha[i] || node->right->alpha[i];
    return node;
}


vector<char> QueryNode(int l, int r, shared_ptr<SegmentTreeNode> cur) {
    if (l <= cur->l && cur->r <= r)
        return cur->alpha;
    if (cur->r < l || r < cur->l)
        return vector<char>(26);

    auto left_result = QueryNode(l, r, cur->left);
    auto right_result = QueryNode(l, r, cur->right);
    vector<char> result(26);
    for (int i = 0; i < 26; ++i)
        result[i] = left_result[i] || right_result[i];
    return result;
}


void UpdateNode(int i, char v, shared_ptr<SegmentTreeNode> cur) {
    if (i < cur->l || cur->r < i)
        return;
    if (i == cur->l && i == cur->r) {
        cur->alpha = vector<char>(26);
        cur->alpha[v-'a'] = true;
        return;
    }

    UpdateNode(i, v, cur->left);
    UpdateNode(i, v, cur->right);
    cur->alpha = vector<char>(26);
    for (int i = 0; i < 26; ++i)
        cur->alpha[i] = cur->left->alpha[i] || cur->right->alpha[i];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int q;
    cin >> q;

    auto root = CreateNode(0, s.size()-1, s);

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            UpdateNode(pos-1, c, root);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            auto alpha = QueryNode(l-1, r-1, root);

            int result = 0;
            for (int i = 0; i < 26; ++i) {
                if (alpha[i])
                    ++result;
            }
            cout << result << endl;
        }
    }
}
