#include <vector>
#include <set>


using namespace std;


class Solution {
  public:
    bool isPossible(vector<int>& nums) {
        multiset<int> pool;
        for (auto& ni : nums)
            pool.emplace(ni);

        while (!pool.empty()) {
            int len = 0;
            auto it = *pool.begin();
            while (it != pool.end()) {
                int next = *it + 1;
                ++len;
                pool.erase(it);
                it = pool.find(next);
            }
            if (len < 3)
                return false;
        }
        return true;
    }
};
