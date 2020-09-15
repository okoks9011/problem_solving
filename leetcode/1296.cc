#include <vector>
#include <multiset>


using namespace std;


class Solution {
  public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k)
            return false;

        multiset<int> buf;
        for (auto& ni : nums)
            buf.emplace(ni);

        for (int i = 0; i < nums.size() / k; ++i) {
            int start = *buf.begin();
            for (int j = 0; j < k; ++j) {
                auto it = buf.find(start+j);
                if (it == buf.end())
                    return false;
                buf.erase(it);
            }
        }
        return true;
    }
};
