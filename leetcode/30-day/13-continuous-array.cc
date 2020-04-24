#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> alter(nums);
        for (auto& a : alter) {
            if (!a)
                a = -1;
        }

        int acc = 0;
        int result = 0;
        unordered_map<int, int> loc;
        loc[0] = -1;
        for (int i = 0; i < alter.size(); ++i) {
            acc += alter[i];
            auto it = loc.find(acc);
            if (it != loc.end())
                result = max(result, i - it->second);
            else
                loc[acc] = i;
        }
        return result;
    }
};
