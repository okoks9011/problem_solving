#include <string>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int calMinInsertion(int left, int right, vector<vector<int>>* dp_ptr, const string& word) {
        if (left >= right)
            return 0;

        auto& dp = *dp_ptr;
        auto& result = dp[left][right];
        if (result != -1)
            return result;

        if (word[left] == word[right]) {
            result = calMinInsertion(left+1, right-1, dp_ptr, word);
        } else {
            result = min(calMinInsertion(left+1, right, dp_ptr, word),
                         calMinInsertion(left, right-1, dp_ptr, word)) + 1;
        }
        return result;
    }

    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return calMinInsertion(0, s.size()-1, &dp, s);
    }
};
