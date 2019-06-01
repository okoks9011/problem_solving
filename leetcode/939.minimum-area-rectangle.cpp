#include <set>
#include <pair>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

class Solution {
  public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> pset;
        for (auto& pi : points)
            pset.emplace(pi[0], pi[1]);

        int result = numeric_limits<int>::max();
        for (int i = 0; i < points.size(); ++i) {
            auto& pi = points[i];
            for (int j = i+1; j < points.size(); ++j) {
                auto& pj = points[j];
                if (pset.find({pi[0], pj[1]}) != pset.end() &&
                    pset.find({pj[0], pi[1]}) != pset.end()) {
                    int new_size = abs(pi[0]-pj[0]) * abs(pi[1]-pj[1]);
                    if (new_size)
                        result = min(result, new_size);
                }
            }
        }
        if (result != numeric_limits<int>::max())
            return result;
        else
            return 0;
    }
};
