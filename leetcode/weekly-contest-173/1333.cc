#include <vector>
#include <algorithm>
#include <utility>


using namespace std;


class Solution {
  public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> elems;
        for (auto& r : restaurants) {
            if (veganFriendly && !r[2])
                continue;
            if (r[3] > maxPrice)
                continue;
            if (r[4] > maxDistance)
                continue;

            elems.emplace_back(r[1], r[0]);
        }

        sort(elems.begin(), elems.end());
        reverse(elems.begin(), elems.end());

        vector<int> result;
        for (auto& p : elems)
            result.emplace_back(p.second);
        return result;
    }
};
