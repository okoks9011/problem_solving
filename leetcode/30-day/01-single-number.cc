#include <vector>


using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto& ni : nums)
            result ^= ni;
        return result;
    }
};
