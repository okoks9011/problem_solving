#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>


using namespace std;


struct TrieNode {
    vector<shared_ptr<TrieNode>> children;
    int cnt = 0;

    TrieNode() : children(26) {}
};


struct Elem {
    int score = 0;
    int removed = 0;

    Elem(int s, int r) : score(s), removed(r) {}
};


class Trie {
  private:
    shared_ptr<TrieNode> root;
    int k = 0;

  public:
    Trie() {
        root = make_shared<TrieNode>();
    }

    void insert(string s) {
        auto node = root;
        for (auto& c : s) {
            int ci = c - 'A';
            if (!node->children[ci])
                node->children[ci] = make_shared<TrieNode>();
            ++(node->cnt);
            node = node->children[ci];
        }
        ++(node->cnt);
    }

    Elem extractScore(shared_ptr<TrieNode> node, int level) {
        assert(node != nullptr);
        if (node->cnt < k)
            return {0, 0};

        int score = 0;
        int cnt = node->cnt;
        for (int i = 0; i < 26; ++i) {
            if (!node->children[i])
                continue;
            auto result = extractScore(node->children[i], level+1);
            score += result.score;
            cnt -= result.removed;
        }

        score += (cnt / k) * level;
        int removed = (node->cnt / k) * k;
        return {score, removed};
    }

    int findMaxScore(int k) {
        this->k = k;
        Elem result = extractScore(root, 0);
        return result.score;
    }
};


int Solve() {
    int n, k;
    cin >> n >> k;

    Trie trie;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        trie.insert(tmp);
    }

    return trie.findMaxScore(k);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << Solve() << endl;
}
