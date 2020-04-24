#include <vector>
#include <limits>


using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = numeric_limits<int>::min();
        int cur = -1;
        for (auto& ni : nums) {
            if (cur <= 0) {
                cur = ni;
            } else {
                cur += ni;
            }
            result = max(result, cur);
        }

        return result;
    }
};
