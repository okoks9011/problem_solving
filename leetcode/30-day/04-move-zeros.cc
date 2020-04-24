#include <vector>
#include <algorithm>
#include <utility>


using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto z_it = find(nums.begin(), nums.end(), 0);
        if (z_it == nums.end())
            return;

        for (auto nz_it = z_it; nz_it != nums.end(); ++nz_it) {
            if (*nz_it) {
                swap(*z_it, *nz_it);
                ++z_it;
            }
        }
    }
};
