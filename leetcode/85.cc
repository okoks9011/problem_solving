#include <vector>
#include <utility>
#include <cassert>


using namespace std;


class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        assert(r != 0);
        int c = matrix[0].size();
        vector<vector<pair<int, int>>> max_size(r+1, vector<pair<int, int>>(c+1, {0, 0}));

        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (matrix[i-1][j-1] == '0')
                    continue;
                auto& left = matrix[i][j-1];
                auto& up = matrix[i-1][j];
                int width = min(left.first+1, up.first);
                int height = min(left.second, up.second+1);
            }
        }
    }
};
