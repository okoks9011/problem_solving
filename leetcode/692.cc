#include <vector>
#include <string>
#include <unordered_map>
#include <queue>


using namespace std;


class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words)
            ++cnt[word];

        priority_queue<pair<int, string>> max_q;
        for (auto& p : cnt) {
            max_q.emplace(-p.second, p.first);
            if (max_q.size() > k)
                max_q.pop();
        }

        vector<string> result;
        while (!max_q.empty()) {
            result.emplace_back(max_q.top().second);
            max_q.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
