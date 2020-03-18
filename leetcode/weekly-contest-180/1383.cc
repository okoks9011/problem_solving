#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <limits>
#include <functional>


using namespace std;


const int kMod = 1000000007;


class Solution {
  public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int, int>> eng(n);
        for (int i = 0; i < n; ++i) {
            eng[i].first = eff[i];
            eng[i].second = speed[i];
        }

        sort(eng.rbegin(), eng.rend());

        priority_queue<int, vector<int>, greater<>> min_pq;
        long long int speed_sum = 0;
        int cur_eff = numeric_limits<int>::max();
        long long int max_perf = 0;
        for (auto& p : eng) {
            cur_eff = min(cur_eff, p.first);

            speed_sum += p.second;
            min_pq.emplace(p.second);
            if (min_pq.size() > k) {
                auto p_out = min_pq.top();
                speed_sum -= p_out;
                min_pq.pop();
            }

            max_perf = max(max_perf, speed_sum * cur_eff);
        }

        return max_perf % kMod;
    }
};
