#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>


using namespace std;


class Solution {
  private:
    vector<vector<int>> dist;
  public:
    Solution() : dist(26, vector<int>(26)) {
        vector<string> grid{
            "ABCDEF",
            "GHIJKL",
            "MNOPQR",
            "STUVWX",
            "YZ",
        };

        for (int y1 = 0; y1 < grid.size(); ++y1) {
            for (int x1 = 0; x1 < grid[y1].size(); ++x1) {
                for (int y2 = 0; y2 < grid.size(); ++y2) {
                    for (int x2 = 0; x2 < grid[y2].size(); ++x2) {
                        int f1 = grid[y1][x1] - 'A';
                        int f2 = grid[y2][x2] - 'A';
                        dist[f1][f2] = abs(y1 - y2) + abs(x1 - x2);
                    }
                }
            }
        }
    }

    int CalMinDist(int f1, int f2, int cur, vector<vector<vector<int>>>* dp_ptr, const string& word) {
        int n = word.size();
        if (cur >= n)
            return 0;

        auto& dp = *dp_ptr;
        auto& result = dp[f1][f2][cur];
        if (result != -1)
            return result;

        int cur_alpha = word[cur] - 'A';
        int f1_result = dist[f1][cur_alpha] + CalMinDist(cur_alpha, f2, cur+1, dp_ptr, word);
        int f2_result = dist[cur_alpha][f2] + CalMinDist(f1, cur_alpha, cur+1, dp_ptr, word);
        result = min(f1_result, f2_result);
        return result;
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(n, -1)));

        int result = numeric_limits<int>::max();
        for (int f1 = 0; f1 < 26; ++f1) {
            for (int f2 = 0; f2 < 26; ++f2)
                result = min(result, CalMinDist(f1, f2, 0, &dp, word));
        }
        return result;
    }
};
