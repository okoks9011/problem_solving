#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    bool collapse(vector<int>& inter1, vector<int>& inter2) {
        return !(inter1[1] < inter2[0]) && !(inter2[1] < inter1[0]);
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
            return {newInterval};

        int n = intervals.size();

        int start = newInterval[0];
        int end = newInterval[1];

        int collapse_start = -1;
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            if (!collapse(intervals[i], newInterval)) {
                result.emplace_back(intervals[i]);
                continue;
            }
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
        }

        vector<int> merged{start, end};
        auto it = lower_bound(result.begin(), result.end(), merged);
        result.insert(it, merged);

        return result;
    }
};
