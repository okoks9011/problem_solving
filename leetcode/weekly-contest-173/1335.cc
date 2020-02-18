#include <vector>
#include <algorithm>


using namespace std;


const int kInf = 123456789;

class Solution {
  public:
    int calMinDifficulty(int i, int day, int n,
                         vector<vector<int>>* dp_ptr, const vector<int>& jobs) {
        if (day == 0 && i == n)
            return 0;
        if (day == 0 || i == n)
            return kInf;

        auto& dp = *dp_ptr;
        auto& result = dp[i][day];
        if (result != -1)
            return result;

        result = kInf;
        int cur = -1;
        for (int j = i; j < n; ++j) {
            cur = max(cur, jobs[j]);
            result = min(result, cur+calMinDifficulty(j+1, day-1, n, dp_ptr, jobs));
        }

        return result;
    }

    int minDifficulty(const vector<int>& jobs, int d) {
        int n = jobs.size();
        vector<vector<int>> dp(n, vector<int>(d+1, -1));

        int result = calMinDifficulty(0, d, n, &dp, jobs);
        if (result == kInf)
            return -1;
        else
            return result;
    }
};
