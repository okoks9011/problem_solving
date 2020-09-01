#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    long long CalMinimumLargest(vector<vector<long long>>* dp_ptr, int i, int k,
                                const vector<int>& nums) {
        if (i < k)
            return numeric_limits<long long>::max();
        if (k == 0) {
            if (i == 0)
                return 0;
            else
                return numeric_limits<long long>::max();
        }

        auto& dp = *dp_ptr;
        auto& result = dp[i][k];
        if (result != -1)
            return result;

        result = numeric_limits<long long>::max();
        long long cur_sum = 0;
        for (int j = 1; j <= i; ++j) {
            cur_sum += nums[i-j];
            long long cur_result = max(CalMinimumLargest(dp_ptr, i-j, k-1, nums), cur_sum);
            result = min(result, cur_result);
        }
        return result;
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1L));
        return static_cast<int>(CalMinimumLargest(&dp, n, m, nums));
    }
};
