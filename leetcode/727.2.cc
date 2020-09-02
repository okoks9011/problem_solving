#include <vector>
#include <string>


using namespace std;


class Solution {
  public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> next(n+1, vector<int>(26));
        for (int i = 0; i < 26; ++i)
            next[n][i] = -1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j)
                next[i][j] = next[i+1][j];
            next[i][s[i]-'a'] = i;
        }

        int start = -1;
        int min_len = n+1;
        for (int left = 0; left < n; ++left) {
            if (s[left] != t[0])
                continue;

            int right = left;
            int ti = 0;
            for (; ti < m; ++ti) {
                right = next[right][t[ti]-'a'];
                if (right == -1)
                    break;
                ++right;
            }

            if (ti != m)
                continue;
            if (min_len > right - left) {
                start = left;
                min_len = right - left;
            }
        }

        if (start == -1)
            return "";
        return s.substr(start, min_len);
    }
};
