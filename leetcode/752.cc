#include <vector>
#include <string>
#include <unordered_set>


using namespace std;


class Solution {
  public:
    vector<string> calAdjs(const string& node) {
        vector<string> result;
        for (int i = 0; i < node.size(); ++i) {
            string tmp(node);
            tmp[i] = (node[i] - '0' + 1) % 10 + '0';
            result.emplace_back(tmp);

            tmp[i] = (node[i] - '0' + 9) % 10 + '0';
            result.emplace_back(tmp);
        }
        return result;
    }

    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1;

        unordered_set<string> visited(deadends.begin(), deadends.end());
        visited.emplace("0000");
        vector<string> cur;
        cur.emplace_back("0000");

        int level = 0;
        while (!cur.empty()) {
            vector<string> next;
            for (auto& node : cur) {
                if (node == target)
                    return level;
                for (auto& adj : calAdjs(node)) {
                    if (visited.find(adj) != visited.end())
                        continue;
                    visited.emplace(adj);
                    next.emplace_back(adj);
                }
            }
            cur = next;
            ++level;
        }
        return -1;
    }
};
