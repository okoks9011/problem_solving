#include <vector>
#include <memory>

using namespace std;

struct TrieNode {
    int cnt = 0;
    bool is_leaf = false;
    vector<shared_ptr<TrieNode>> children;
    TrieNode() : children(26) {}
};

class Solution {
  public:
    void insertTrie(string s, shared_ptr<TrieNode> node) {
        for (auto& c : s) {
            ++(node->cnt);
            int cur = c - 'a';
            if (!node->children[cur])
                node->children[cur] = make_shared<TrieNode>();
            node = node->children[cur];
        }
        ++(node->cnt);
        node->is_leaf = true;
    }

    string extractAbbrev(string s, shared_ptr<TrieNode> node) {
        string result;
        int depth = 0;
        for (auto& c : s) {
            int cur = c - 'a';
            node = node->children[cur];
            ++depth;
            result += c;
            if (node->cnt == 1)
                break;
        }
        int remain = s.size() - depth;
        if (remain > 1)
            result += to_string(remain);
        else if (remain == 1)
            result += s.back();

        return result;
    }

    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<vector<shared_ptr<TrieNode>>> trie(401, vector<shared_ptr<TrieNode>>(26));
        for (auto s : dict) {
            int size = s.size();
            int last = s.back() - 'a';
            if (!trie[size][last])
                trie[size][last] = make_shared<TrieNode>();
            s.pop_back();
            insertTrie(s, trie[size][last]);
        }

        vector<string> result;
        for (auto s : dict) {
            int size = s.size();
            if (size == 1) {
                result.emplace_back(s);
                continue;
            }

            int last = s.back() - 'a';
            s.pop_back();

            string abb = extractAbbrev(s, trie[size][last]);
            abb += (last + 'a');
            result.emplace_back(abb);
        }
        return result;
    }
};
