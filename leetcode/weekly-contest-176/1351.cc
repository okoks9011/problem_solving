#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (auto& row : grid)
            result += count_if(row.begin(), row.end(), [](int v){ return v < 0; });
        return result;
    }
};
