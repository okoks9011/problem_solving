#include <utility>
#include <vector>
#include <string>


using namespace std;


class Solution {
  public:
    vector<pair<char, int>> makeGroups(const string& s) {
        vector<pair<char, int>> groups;
        char last = s[0];
        int len = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (last != s[i]) {
                groups.emplace_back(last, len);
                last = s[i];
                len = 1;
            } else {
                ++len;
            }
        }
        groups.emplace_back(last, len);
        return groups;
    }

    bool isStrechy(const string& s, const string& w) {
        auto sg = makeGroups(s);
        auto wg = makeGroups(w);
        if (sg.size() != wg.size())
            return false;

        for (int i = 0; i < sg.size(); ++i) {
            if (sg[i].first != wg[i].first)
                return false;
            if (sg[i].second == wg[i].second)
                continue;
            if (sg[i].second < wg[i].second || sg[i].second < 3)
                return false;
        }
        return true;
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
