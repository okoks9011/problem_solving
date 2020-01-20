#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<pair<int, int>> alpha;

    vector<pair<int, int>> genAlpha() {
        vector<pair<int, int>> result(26);
        int x = 0;
        int y = 0;
        for (int i = 0; i < 26; ++i) {
            result[i] = {x, y};
            ++x;
            if (x > 5) {
                ++y;
                x = 0;
            }
        }
        return result;
    }

    int getDistance(int i, int j) {
        auto loc_i = alpha[i];
        auto loc_j = alpha[j];
        return abs(loc_i.first-loc_j.first) + abs(loc_i.second-loc_j.second);
    }

    int calMinDistance(int i, int j, int cur, const string word,
                       vector<vector<vector<int>>>* dp_ptr) {
        if (cur >= word.size())
            return 0;

        auto& dp = *dp_ptr;
        auto& result = dp[i][j][cur];
        if (result != -1)
            return result;

        int c = word[cur] - 'A';
        int first = getDistance(i, c) + calMinDistance(c, j, cur+1, word, dp_ptr);
        int second = getDistance(j, c) + calMinDistance(i, c, cur+1, word, dp_ptr);
        result = min(first, second);

        return result;
    }

    int minimumDistance(string word) {
        alpha = genAlpha();

        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(word.size(), -1)));
        int dist = numeric_limits<int>::max();
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                int cur = calMinDistance(i, j, 0, word, &dp);
                if (cur < dist)
                    dist = cur;
            }
        }
        return dist;
    }
};
