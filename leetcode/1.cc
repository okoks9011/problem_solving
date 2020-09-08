#include <vector>
#include <unordered_map>
#include <cassert>


using namespace std;


class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> loc;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = loc.find(target - nums[i]);
            if (it != loc.end())
                return {it->second, i};

            loc[nums[i]] = i;
        }
        assert(false);
    }
};
