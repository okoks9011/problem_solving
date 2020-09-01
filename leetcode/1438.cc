#include <map>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int longestSubarray(vector<int>& nums, int limit) {
        int end = 0;
        map<int, int> cnt;
        int result = 0;
        for (int start = 0; start < n; ++start) {
            while (end < n && (cnt.empty() || (cnt.end())->first - (cnt.begin())->first <= limit))
                ++cnt[nums[end++]];
            result = max(result, end-start);

            int tail = nums[start];
            --cnt[tail];
            if (cnt[tail] == 0)
                cnt.erase(tail);
        }

        return result;
    }
};
