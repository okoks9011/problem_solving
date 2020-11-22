#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
  public:
    int CalLongest(int ci, vector<int>* dp_ptr,
                   const vector<string>& words,
                   const unordered_map<string, int>& loc) {
        auto& dp = *dp_ptr;
        auto& result = dp[ci];
        if (result != -1)
            return result;

        auto& word = words[ci];
        if (word.size() == 1) {
            result = 1;
            return 1;
        }

        result = 0;
        for (int i = 0; i < word.size(); ++i) {
            string sub = word.substr(0, i) + word.substr(i+1);
            auto it = loc.find(sub);
            if (it == loc.end())
                continue;
            result = max(result, CalLongest(it->second, dp_ptr, words, loc));
        }
        ++result;
        return result;
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> loc;
        for (int i = 0; i < words.size(); ++i)
            loc[words[i]] = i;
        vector<int> dp(words.size(), -1);

        int result = 0;
        for (int i = 0; i < words.size(); ++i)
            result = max(result, CalLongest(i, &dp, words, loc));
        return result;
    }
};
