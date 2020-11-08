#include <vector>
#include <cassert>
#include <limits>


using namespace std;


class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        assert(r > 0);
        int c = matrix[0].size();
        assert(c > 0);

        vector<vector<int>> acc(r+1, vector<int>(c+1));
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                acc[i][j] = matrix[i-1][j-1];
                acc[i][j] += acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
            }
        }

        int result = numeric_limits<int>::min();
        for (int y1 = 0; y1 <= r; ++y1) {
            for (int y2 = y1+1; y2 <= r; ++y2) {
                for (int x1 = 0; x1 <= c; ++x1) {
                    for (int x2 = x1+1; x2 <= c; ++x2) {
                        int sum = acc[y2][x2] - acc[y1][x2] - acc[y2][x1] + acc[y1][x1];
                        if (sum > k)
                            continue;
                        result = max(result, sum);
                        if (result == k)
                            break;
                    }
                }
            }
        }
        return result;
    }
};
