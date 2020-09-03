#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>


using namespace std;


class Solution {
  public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> subseq;
        for (auto& x : nums) {
            int len = 1;
            auto it = subseq.find(x-1);
            if (it != subseq.end() && !(it->second.empty())) {
                auto& min_pq = it->second;
                len += min_pq.top();
                min_pq.pop();
            }
            subseq[x].emplace(len);
        }

        for (auto& p : subseq) {
            auto& pq = p.second;
            if (!pq.empty() && pq.top() < 3)
                return false;
        }
        return true;
    }
};
