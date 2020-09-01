#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> cnt;
        int j = 0;
        int result = 0;
        for (int i = 0; i < tree.size(); ++i) {
            ++cnt[tree[i]];
            while (cnt.size() > 2) {
                --cnt[tree[j]];
                if (cnt[tree[j]] == 0)
                    cnt.erase(tree[j]);
                ++j;
            }
            result = max(result, i-j+1);
        }
        return result;
    }
};
