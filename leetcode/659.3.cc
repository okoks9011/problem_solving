#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
  public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> remain;
        for (auto& x : nums)
            ++remain[x];

        unordered_map<int, int> last;
        for (auto& x : nums) {
            if (remain[x] == 0)
                continue;
            --remain[x];

            auto it = last.find(x-1);
            if (it != last.end() && it->second > 0) {
                --(it->second);
                ++last[x];
            } else if (remain[x+1] > 0 && remain[x+2] > 0) {
                --remain[x+1];
                --remain[x+2];
                ++last[x+2];
            } else {
                return false;
            }
        }
        return true;
    }
};
