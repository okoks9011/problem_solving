#include <vector>
#include <algorithm>
#include <limits>


using namespace std;


class Solution {
  public:
    int CalMinGuess(int left, int right, vector<vector<int>>* dp_ptr) {
        if (left >= right)
            return 0;
        auto& dp = *dp_ptr;
        auto& result = dp[left][right];
        if (result != -1)
            return result;

        result = numeric_limits<int>::max();
        for (int i = left; i <= right; ++i) {
            int cur = max(CalMinGuess(left, i-1, dp_ptr), CalMinGuess(i+1, right, dp_ptr));
            result = min(result, cur+i);
        }
        return result;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return CalMinGuess(1, n, &dp);
    }
};
