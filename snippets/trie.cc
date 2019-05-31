#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

struct TrieANode {
    vector<shared_ptr<TrieANode>> children;
    bool is_leaf = false;

    TrieANode() : children(26) {}
};

class TrieA {
  private:
    shared_ptr<TrieANode> root;

  public:
    TrieA() {
        root = make_shared<TrieANode>();
    }

    void insert(string s) {
        auto node = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = make_shared<TrieANode>();
            node = node->children[idx];
        }
        node->is_leaf = true;
    }

    bool search(string s) {
        auto node = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->is_leaf;
    }

    bool startsWith(string s) {
        auto node = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};


struct TrieHNode {
    unordered_map<char, shared_ptr<TrieHNode>> children;
    bool is_leaf = false;
};

class TrieH {
  private:
    shared_ptr<TrieHNode> root;

  public:
    TrieH() {
        root = make_shared<TrieHNode>();
    }

    void insert(string s) {
        auto node = root;
        for (auto& c : s) {
            if (!node->children[c])
                node->children[c] = make_shared<TrieHNode>();
            node = node->children[c];
        }
        node->is_leaf = true;
    }

    bool search(string s) {
        auto node = root;
        for (auto& c : s) {
            if (!node->children[c])
                return false;
            node = node->children[c];
        }
        return node->is_leaf;
    }

    bool startsWith(string s) {
        auto node = root;
        for (auto& c : s) {
            if (!node->children[c])
                return false;
            node = node->children[c];
        }
        return true;
    }
};
