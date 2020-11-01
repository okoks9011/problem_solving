#include <string>
#include <vector>


using namespace std;


class Solution {
  public:
    int CalMinStep(int ci, int cj, vector<vector<int>>* dp_ptr,
                   const string& s) {
        if (ci >= cj)
            return 0;
        auto& dp = *dp_ptr;
        auto& result = dp[ci][cj];
        if (result != -1)
            return result;

        if (s[ci] == s[cj]) {
            result = CalMinStep(ci+1, cj-1, dp_ptr, s);
        } else {
            result = min(CalMinStep(ci, cj-1, dp_ptr, s),
                         CalMinStep(ci+1, cj, dp_ptr, s));
            ++result;
        }
        return result;
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return CalMinStep(0, n-1, &dp, s);
    }
};
