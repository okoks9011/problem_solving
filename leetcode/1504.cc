#include <vector>
#include <cassert>


using namespace std;


class Solution {
  public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        assert(n > 0);
        int m = mat[0].size();
        assert(m > 0);

        vector<vector<int>> acc(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                acc[i][j] = acc[i-1][j] + acc[i][j-1] - acc[i-1][j-1];
                if (mat[i-1][j-1] == 1)
                    ++acc[i][j];
            }
        }
        int result = 0;
        for (int i1 = 0; i1 <= n; ++i1) {
            for (int i2 = i1+1; i2 <= n; ++i2) {
                for (int j1 = 0; j1 <= m; ++j1) {
                    for (int j2 = j1+1; j2 <= m; ++j2) {
                        int sum = acc[i2][j2] - acc[i1][j2] - acc[i2][j1] + acc[i1][j1];
                        if (sum == (i2 - i1) * (j2 - j1))
                            ++result;
                    }
                }
            }
        }
        return result;
    }
};
