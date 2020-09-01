#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

class Solution {
  public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> point_set;
        for (auto& point : points)
            point_set.emplace(point[0], point[1]);

        int n = points.size();
        int min_size = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            auto& p1 = points[i];
            for (int j = i+1; j < n; ++j) {
                auto& p2 = points[j];
                if (p1[0] == p2[0] || p1[1] == p2[1])
                    continue;
                if (point_set.find({p1[0], p2[1]}) == point_set.end() ||
                    point_set.find({p2[0], p1[1]}) == point_set.end())
                    continue;
                int new_size = abs(p1[0]-p2[0]) * abs(p1[1]-p2[1]);
                min_size = min(min_size, new_size);
            }
        }

        if (min_size == numeric_limits<int>::max())
            return 0;
        return min_size;
    }
};
