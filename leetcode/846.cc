#include <set>


using namespace std;


class Solution {
  public:
    bool isNStraightHand(vector<int>& hand, int w) {
        if (hand.size() % w)
            return false;

        multiset<int> pool;
        for (auto& h : hand)
            pool.emplace(h);

        for (int i = 0; i < hand.size() / w; ++i) {
            int start = *pool.begin();
            for (int j = 0; j < w; ++j) {
                auto it = pool.find(start+j);
                if (it == pool.end())
                    return false;
                pool.erase(it);
            }
        }
        return true;
    }
};
