#include <vector>
#include <utility>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> inters;
        for (int i = 0; i <= n; ++i)
            inters.emplace_back(i-ranges[i], i+ranges[i]);
        sort(inters.begin(), inters.end());

        int cur = 0;
        int idx = 0;
        int cnt = 0;
        while (cur < n) {
            int next = cur;
            while (inters[idx].first <= cur) {
                next = max(next, inters[idx].second);
                ++idx;
            }
            if (next == cur)
                return -1;
            cur = next;
            ++cnt;
        }
        return cnt;
    }
};
