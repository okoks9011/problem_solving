#include <vector>
#include <string>


using namespace std;


class Solution {
  public:
    bool isStrechy(const string& s, const string& w) {
        int n = s.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < m && s[i] == w[j]) {
                ++j;
                continue;
            } else if ((i > 0 && i < n-1 && s[i-1] == s[i] && s[i] == s[i+1]) ||
                       (i > 1 && s[i-2] == s[i-1] && s[i-1] == s[i])) {
                continue;
            }
            return false;
        }
        return j == w.size();
    }

    int expressiveWords(string s, vector<string>& words) {
        int result = 0;
        for (auto& w : words) {
            if (isStrechy(s, w))
                ++result;
        }
        return result;
    }
};
