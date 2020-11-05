#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int CalMax(int cur_i, int cur_m, vector<vector<int>>* dp_ptr,
               const vector<int>& suf) {
        auto& dp = *dp_ptr;
        int n = dp.size();
        if (cur_i >= n)
            return 0;
        if (cur_i + 2 * cur_m >= n)
            return suf[cur_i];

        auto& result = dp[cur_i][cur_m];
        if (result != -1)
            return result;
        for (int x = 1; x <= cur_m * 2; ++x)
            result = max(result, suf[cur_i] - CalMax(cur_i + x, max(x, cur_m), dp_ptr, suf));
        return result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(51, -1));

        vector<int> suf(n+1);
        for (int i = n-1; i >= 0; --i)
            suf[i] = suf[i+1] + piles[i];
        return CalMax(0, 1, &dp, suf);
    }
};
