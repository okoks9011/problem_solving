#include <algorithm>
#include <string>
#include <utility>

using namespace std;

class Solution {
  public:
    vector<pair<char, int>> genIndexPair(const string& s) {
        vector<pair<char, int>> result;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'L' || s[i] == 'R')
                result.emplace_back(s[i], i);
        }
        return result;
    }

    bool canTransform(string from, string to) {
        if (from.size() != to.size())
            return false;

        if (count(from.begin(), from.end(), 'X') != count(to.begin(), to.end(), 'X'))
            return false;

        auto from_idx = genIndexPair(from);
        auto to_idx = genIndexPair(to);
        for (int i = 0; i < from_idx.size(); ++i) {
            auto& from_p = from_idx[i];
            auto& to_p = to_idx[i];
            if (from_p.first != to_p.first)
                return false;
            if (from_p.first == 'R' && from_p.second > to_p.second)
                return false;
            if (from_p.first == 'L' && from_p.second < to_p.second)
                return false;
        }
        return true;
    }
};
