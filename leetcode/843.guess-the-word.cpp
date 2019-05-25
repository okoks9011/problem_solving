#include <vector>
#include <string>
#include <random>
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

mt19937 rng(17);

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
        for (int i = 0; i < 10; ++i) {
            uniform_int_distribution<> dis(0, candi.size()-1);
            string pick = candi[dis(rng)];
            int cnt = master.guess(pick);
            if (cnt == 6)
                break;

            vector<string> next;
            for (auto& s : candi) {
                if (countMatch(pick, s) == cnt)
                    next.emplace_back(s);
            }
            candi = next;
        }
    }
};
