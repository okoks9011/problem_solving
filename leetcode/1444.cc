#include <vector>
#include <string>
#include <cassert>


using namespace std;


const int kMod = 1000000007;

class Solution {
  public:
    int CalCut(int cur_i, int cur_j, int remain, vector<vector<vector<int>>>* dp_ptr,
               const vector<vector<int>>& apples) {
        if (remain == 1)
            return 1;
        int r = apples.size() - 1;
        int c = apples[0].size() - 1;
        auto& dp = *dp_ptr;
        auto& result = dp[cur_i][cur_j][remain];
        if (result != -1)
            return result;

        result = 0;
        for (int y = cur_i+1; y < r && apples[y][cur_j] >= remain - 1; ++y) {
            if (apples[cur_i][cur_j] - apples[y][cur_j] > 0) {
                result += CalCut(y, cur_j, remain-1, dp_ptr, apples);
                result %= kMod;
            }
        }
        for (int x = cur_j+1; x < c && apples[cur_i][x] >= remain - 1; ++x) {
            if (apples[cur_i][cur_j] - apples[cur_i][x] > 0) {
                result += CalCut(cur_i, x, remain-1, dp_ptr, apples);
                result %= kMod;
            }
        }

        return result;
    }

    int ways(vector<string>& pizza, int k) {
        int r = pizza.size();
        assert(r > 0);
        int c = pizza[0].size();
        assert(c > 0);

        vector<vector<int>> apples(r+1, vector<int>(c+1));
        for (int i = r-1; i >= 0; --i) {
            int row_cnt = 0;
            for (int j = c-1; j >= 0; --j) {
                if (pizza[i][j] == 'A')
                    ++row_cnt;
                apples[i][j] = apples[i+1][j] + row_cnt;
            }
        }

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(k+1, -1)));
        auto result = CalCut(0, 0, k, &dp, apples);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                cout << apples[i][j] << " ";
            cout << endl;
        }
        return result;
    }
};
