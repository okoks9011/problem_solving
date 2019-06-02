#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
  public:
    vector<pair<char, int>> calChunk(const string& s) {
        vector<pair<char, int>> result;
        for (int i = 0; i < s.size(); ++i) {
            int j = i;
            while (j < s.size() && s[i] == s[j])
                ++j;
            result.emplace_back(s[i], j-i);
            i = j-1;
        }
        return result;
    }

    bool strechyable(const vector<pair<char, int>>& s_chunk,
                     const string& word) {
        auto w_chunk = calChunk(word);
        if (s_chunk.size() != w_chunk.size())
            return false;

        for (int i = 0; i < s_chunk.size(); ++i) {
            if (s_chunk[i].first != w_chunk[i].first)
                return false;
            if (s_chunk[i].second < w_chunk[i].second)
                return false;
            if (s_chunk[i].second > w_chunk[i].second && s_chunk[i].second < 3)
                return false;
        }
        return true;
    }

    int expressiveWords(string s, vector<string>& words) {
        auto s_chunk = calChunk(s);

        int result = 0;
        for (auto& word : words)
            result += strechyable(s_chunk, word);
        return result;
    }
};
