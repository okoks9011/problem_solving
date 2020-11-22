#include <vector>
#include <string>
#include <unordered_set>


using namespace std;


class Solution {
  public:
    unordered_set<string> CalNeighbors(const string& word, const unordered_set<string>& word_set) {
        unordered_set<string> result;
        for (int i = 0; i < word.size(); ++i) {
            string tmp = word;
            for (char c = 'a'; c <= 'z'; ++c) {
                tmp[i] = c;
                if (tmp == word || word_set.find(tmp) == word_set.end())
                    continue;
                result.emplace(tmp);
            }
        }
        return result;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        unordered_set<string> visited{beginWord};
        vector<string> cur_q{beginWord};
        int level = 1;
        while (!cur_q.empty()) {
            vector<string> next_q;
            for (auto& word : cur_q) {
                auto neighbors = CalNeighbors(word, word_set);
                for (auto& nei : neighbors) {
                    if (nei == endWord)
                        return level + 1;
                    if (visited.find(nei) != visited.end())
                        continue;
                    visited.emplace(nei);
                    next_q.emplace_back(nei);
                }
            }
            cur_q = next_q;
            ++level;
        }
        return 0;
    }
};
