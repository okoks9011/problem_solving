#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int acc = 0;
        int result = 0;
        cnt[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            acc += nums[i];
            auto it = cnt.find(acc-k);
            if (it != cnt.end())
                result += it->second;
            ++cnt[acc];
        }
        return result;
    }
};
