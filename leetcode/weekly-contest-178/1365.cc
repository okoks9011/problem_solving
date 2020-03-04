#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            result[i] = count_if(nums.begin(), nums.end(), [&](int v){ return v < nums[i]; });
        return result;
    }
};
