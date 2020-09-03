#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int getSpreadTime(int cur, const vector<vector<int>>& adjs,
                      const vector<int>& informTime) {
        if (adjs[cur].empty())
            return 0;

        int result = 0;
        for (auto& v : adjs[cur])
            result = max(result, getSpreadTime(v, adjs, informTime));
        return result + informTime[cur];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjs(n);
        for (int i = 0; i < n; ++i) {
            if (i == headID)
                continue;
            adjs[manager[i]].emplace_back(i);
        }

        return getSpreadTime(headID, adjs, informTime);
    }
};
