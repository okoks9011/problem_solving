#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
  public:
    int countMatch(const string& s1, const string& s2) {
        if (s1.size() != s2.size())
            return 0;

        int result = 0;
        for (int i = 0; i < s1.size(); ++i)
            result += s1[i] == s2[i];
        return result;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<string> candi(wordlist);
        for (int k = 0; k < 10; ++k) {
            vector<int> zero_cnt(candi.size());
            for (int i = 0; i < candi.size(); ++i) {
                for (int j = 0; j < candi.size(); ++j) {
                    if (countMatch(candi[i], candi[j]) == 0)
                        ++zero_cnt[i];
                }
            }

            int pick_idx = min_element(zero_cnt.begin(), zero_cnt.end()) - zero_cnt.begin();
            string& pick = candi[pick_idx];

            int match = master.guess(pick);
            if (match == 6)
                break;

            vector<string> next;
            for (auto& cur : candi) {
                if (countMatch(cur, pick) == match)
                    next.emplace_back(cur);
            }
            candi = next;
        }
    }
};
