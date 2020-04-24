#include <vector>


using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = 1;

        for (int i = 0; i < result.size()-1; ++i)
            result[i+1] = result[i] * nums[i];

        int cur = 1;
        for (int i = result.size()-1; i >= 1; --i) {
            cur = cur * nums[i];
            result[i-1] *= cur;
        }

        return result;
    }
};
