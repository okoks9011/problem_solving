#include <string>


using namespace std;


class Solution {
  public:
    string minWindow(string s, string t) {
        string result;
        for (int i = 0; i < s.size() - t.size() + 1; ++i) {
            if (s[i] != t[0])
                continue;
            int k = 0;
            int j = i;
            for (; j < s.size(); ++j) {
                if (s[j] == t[k])
                    ++k;
                if (k >= t.size())
                    break;
            }
            if (k != t.size())
                continue;
            if (result.empty() || j-i+1 < result.size())
                result = s.substr(i, j-i+1);
        }
        return result;
    }
};
