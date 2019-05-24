#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end());
        priority_queue<int, vector<int>, greater<int>> min_pq;
        for (int i = 0; i < inter.size(); ++i) {
            auto& cur = inter[i];
            if (!min_pq.empty() && min_pq.top() <= cur[0])
                min_pq.pop();
            min_pq.emplace(cur[1]);
        }
        return min_pq.size();
    }
};
