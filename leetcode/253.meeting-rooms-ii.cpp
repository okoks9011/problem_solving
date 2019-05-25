#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& meets) {
        sort(meets.begin(), meets.end());
        priority_queue<int, vector<int>, greater<int>> min_pq;

        for (auto& meet : meets) {
            if (!min_pq.empty() && min_pq.top() <= meet[0])
                min_pq.pop();
            min_pq.emplace(meet[1]);
        }
        return min_pq.size();
    }
};
