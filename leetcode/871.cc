#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel)
            return 0;

        int n = stations.size();
        sort(stations.begin(), stations.end());
        priority_queue<int> max_pq;
        int cur = startFuel;
        int i = 0;
        int cnt = 0;
        while (cur < target) {
            while (i < n && stations[i][0] <= cur) {
                max_pq.emplace_back(station[i][1]);
                ++i;
            }
            if (max_pq.empty())
                return -1;
            cur += max_pq.top();
            max_pq.pop();
            ++cnt;
        }
        return cnt;
    }
};
