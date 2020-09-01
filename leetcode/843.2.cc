#include <random>
#include <cassert>

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
    int countMatch(const string& a, const string& b) {
        int result = 0;
        for (int  i = 0; i < a.size(); ++i) {
            if (a[i] == b[i])
                ++result;
        }
        return result;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        vector<string> candi(wordlist);
        random_device rd;
        mt19937 rng(rd());
        for (int i = 0; i < 10; ++i) {
            assert(!candi.empty());
            uniform_int_distribution<> dis(0, candi.size()-1);
            string cur = candi[dis(rng)];
            int match = master.guess(cur);
            if (match == 6)
                return;
            vector<string> next_candi;
            for (auto& w : candi) {
                if (candi == cur)
                    continue;
                if (countMatch(w, cur) == match)
                    next_candi.emplace_back(string);
            }
            candi = next_candi;
        }
        assert(false);
    }
};
