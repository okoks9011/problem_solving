#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <cassert>


using namespace std;


class Solution {
  public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();
        for (int i = 0; i < n; ++i) {
            paragraph[i] = tolower(paragraph[i]);
            if (!isalpha(paragraph[i]))
                paragraph[i] = ' ';
        }

        unordered_map<string, int> cnt;
        stringstream ss(paragraph);
        string word;
        while (ss >> word)
            ++cnt[word];

        for (auto& b : banned)
            cnt.erase(b);

        int max_cnt = 0;
        string result;
        for (auto& p : cnt) {
            if (p.second > max_cnt) {
                max_cnt = p.second;
                result = p.first;
            }
        }
        assert(result != "");

        return result;
    }
};
