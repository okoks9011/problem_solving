#include <vector>
#include <limits>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int CalMaxSum(int cur, int cur_turn, vector<vector<int>>* dp_ptr, const vector<int>& suf) {
        auto& dp = *dp_ptr;
        if (cur >= dp.size())
            return 0;

        auto& result = dp[cur][cur_turn];
        if (result != -1)
            return result;

        int other_sum = numeric_limits<int>::max();
        int other_turn = cur_turn ? 0 : 1;
        for (int i = 1; i <= 3; ++i)
            other_sum = min(other_sum, CalMaxSum(cur+i, other_turn, dp_ptr, suf));
        result = suf[cur] - other_sum;
        return result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suf(n+1);
        for (int i = n-1; i >= 0; --i)
            suf[i] = suf[i+1] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(2, -1));
        int alice = CalMaxSum(0, 1, &dp, suf);
        int bob = suf[0] - alice;
        if (alice > bob)
            return "Alice";
        else if (alice < bob)
            return "Bob";
        else
            return "Tie";
    }
};
