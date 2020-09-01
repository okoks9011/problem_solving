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
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        vector<vector<int>> same(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            auto& wi = wordlist[i];
            for (int j = 0; j < n; ++j) {
                auto& wj = wordlist[j];
                for (int k = 0; k < 6; ++k) {
                    if (wi[k] == wj[k])
                        ++same[i][j];
                }
            }
        }

        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<> dis(0, n-1);

        vector<char> visited(n);
        int cur = 0;
        int cur_same = 0;
        while (cur_same < 3) {
            cur = dis(rng);
            if (!visited[cur])
                cur_same = master.guess(wordlist[cur]);
            visited[cur] = true;
        }
        for (int i = 0; i < 10; ++i) {
            if (cur_same == 6)
                return;

            for (int j = 0; j < n; ++j) {
                if (visited[j] || same[cur][j] < cur_same)
                    continue;
                int new_same = master.guess(wordlist[j]);
                visited[j] = true;
                if (cur_same < new_same) {
                    cur = j;
                    cur_same = new_same;
                    break;
                }
            }
        }
    }
};
