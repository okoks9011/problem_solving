#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool SplitWith(const vector<int>& nums, int m, long long max_sum) {
        int cnt = 1;
        long long sum = 0;
        for (auto& ni : nums) {
            if (sum + ni <= max_sum) {
                sum += ni;
            } else {
                sum = ni;
                ++cnt;
            }

            if (cnt > m)
                return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = *max_element(nums.begin(), nums.end());
        long long right = 0;
        for (auto& ni : nums)
            right += ni;

        long long result = -1;
        while (left <= right) {
            auto mid = left + (right-left) / 2;
            if (SplitWith(nums, m, mid)) {
                right = mid - 1;
                result = mid;
            } else {
                left = mid + 1;
            }
        }

        return static_cast<int>(result);
    }
};
