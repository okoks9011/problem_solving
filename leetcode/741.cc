#include <vector>
#include <algorithm>


using namespace std;


enum CellType {
    kBlocked = -1,
    kUnknown = -2,
};


class Solution {
  public:
    int FindMaxCherry(int y1, int x1, int y2, int x2,
                      vector<vector<vector<vector<int>>>>* dp_ptr,
                      vector<vector<int>>& grid) {
        if (y1 < 0 || x1 < 0 || y2 < 0 || x2 < 0)
            return kBlocked;
        if (y1 == 0 && x1 == 0 && y2 == 0 && x2 == 0)
            return grid[0][0];

        auto& dp = *dp_ptr;
        auto& result = dp[y1][x1][y2][x2];
        if (result != kUnknown)
            return result;

        result = kBlocked;
        if (grid[y1][x1] == -1 || grid[y2][x2] == -1)
            return result;

        vector<pair<int, int>> ds{
            {-1, 0}, {0, -1}
        };
        for (auto& d1 : ds) {
            for (auto& d2 : ds) {
                int pre_y1 = y1 + d1.first;
                int pre_x1 = x1 + d1.second;
                int pre_y2 = y2 + d2.first;
                int pre_x2 = x2 + d2.second;
                int cur = FindMaxCherry(pre_y1, pre_x1, pre_y2, pre_x2, dp_ptr, grid);
                result = max(result, cur);
            }
        }
        if (result == kBlocked)
            return result;
        if (grid[y1][x1] == 1)
            ++result;
        if (((y1 != y2) || (x1 != x2)) && grid[y2][x2] == 1)
            ++result;
        return result;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n,
                                               vector<vector<vector<int>>>(n,
                                                                           vector<vector<int>>(n,
                                                                                               vector<int>(n, kUnknown))));

        int result = FindMaxCherry(n-1, n-1, n-1, n-1, &dp, grid);
        if (result == kBlocked)
            return 0;
        else
            return result;
    }
};
