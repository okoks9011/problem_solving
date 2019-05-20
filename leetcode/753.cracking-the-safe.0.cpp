#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    void genAllNodes(int n, int k, string cur, unordered_map<string, int>* result_ptr) {
        auto& result = *result_ptr;
        if (cur.size() == n) {
            result.emplace(cur, 0);
            return;
        }

        for (int i = 0; i < k; ++i) {
            cur += static_cast<char>(i+'0');
            genAllNodes(n, k, cur, result_ptr);
            cur.pop_back();
        }
    }

    void dfs(int here, char tag, const unordered_map<string, int>& nodes,
             vector<vector<char>>* adj_ptr, string* result_ptr) {
        auto& adj = *adj_ptr;
        int total = adj.size();
        for (int there = 0; there < total; ++there) {
            if (adj[here][there] == 0)
                continue;
            int next_tag = adj[here][there];
            adj[here][there] = 0;
            dfs(there, next_tag, nodes, adj_ptr, result_ptr);
        }
        auto& result = *result_ptr;
        result += tag;
    }

    string crackSafe(int n, int k) {
        if (n == 1) {
            string result;
            for (int i = 0; i < k; ++i)
                result += static_cast<char>(i+'0');
            return result;
        }

        unordered_map<string, int> nodes;
        genAllNodes(n-1, k, "", &nodes);
        int total = 0;
        for (auto& p : nodes) {
            p.second = total;
            ++total;
        }

        vector<vector<char>> adj(total, vector<char>(total));
        for (auto& p : nodes) {
            const string& cur = p.first;
            int i = p.second;
            string next(cur.begin()+1, cur.end());
            for (int j = 0; j < k; ++j) {
                char next_ch = static_cast<char>(j+'0');
                next += next_ch;
                adj[i][nodes[next]] = next_ch;
                next.pop_back();
            }
        }
        auto start = nodes.begin()->first;
        string result;
        dfs(0, start.back(), nodes, &adj, &result);

        string tail(start.begin(), start.end()-1);
        reverse(tail.begin(), tail.end());
        result += tail;
        return result;
    }
};
