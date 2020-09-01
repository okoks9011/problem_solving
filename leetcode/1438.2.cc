#include <set>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start = 0;
        multiset<int> cur;
        int result = 0;
        for (int end = 0; end < nums.size(); ++end) {
            cur.emplace(nums[end]);
            while (!cur.empty() && *cur.rbegin() - *cur.begin() > limit)
                cur.erase(cur.find(nums[start++]));
            result = max(result, end - start + 1);
        }

        return result;
    }
};
