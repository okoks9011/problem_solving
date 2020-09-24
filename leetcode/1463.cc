#include <vector>
#include <cassert>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        assert(n > 0);
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));
        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j)
                dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
        }

        for (int k = n-2; k >= 0; --k) {
            for (int i = 0; i < m; ++i) {
                for (int j = i+1; j < m; ++j) {

                    for (int ni = i-1; ni <= i+1; ++ni) {
                        for (int nj = j-1; nj <= j+1; ++nj) {
                            if (ni < 0 || m <= ni || nj < 0 || m <= nj)
                                continue;
                            if (ni >= nj)
                                continue;
                            dp[k][i][j] = max(dp[k][i][j], dp[k+1][ni][nj]);
                        }
                    }
                    dp[k][i][j] += grid[k][i] + grid[k][j];
                }
            }
        }
        return dp[0][0][m-1];
    }
};
