#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int CalMaxPath(int cur_i, int cur_j, vector<vector<int>>* dp_ptr,
                   const vector<vector<int>>& matrix) {
        auto& dp = *dp_ptr;
        auto& result = dp[cur_i][cur_j];
        if (result != -1)
            return result;

        vector<pair<int, int>> ds{
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };
        int n = matrix.size();
        int m = matrix[0].size();
        result = 0;
        for (auto& d : ds) {
            int new_i = cur_i + d.first;
            int new_j = cur_j + d.second;
            if (new_i < 0 || n <= new_i || new_j < 0 || m <= new_j)
                continue;
            if (matrix[new_i][new_j] > matrix[cur_i][cur_j])
                result = max(result, CalMaxPath(new_i, new_j, dp_ptr, matrix));
        }
        ++result;
        return result;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (m == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int max_path = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                max_path = max(max_path, CalMaxPath(i, j, &dp, matrix));
        }
        return max_path;
    }
};
