#include <algorithm>
#include <vector>
#include <limits>


using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int>> dp(grid);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0 && j == 0)
                    continue;
                int upper = 0 < i ? dp[i-1][j] : numeric_limits<int>::max();
                int left = 0 < j ? dp[i][j-1] : numeric_limits<int>::max();
                dp[i][j] += min(upper, left);
            }
        }
        return dp.back().back();
    }
};
