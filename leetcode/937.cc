#include <vector>
#include <utility>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
  public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letters;
        for (auto& log : logs) {
            if ('0' <= log.back() && log.back() <= '9')
                continue;
            auto sp = log.find(' ');
            letters.emplace_back(log.substr(sp), log.substr(0, sp));
        }
        sort(letters.begin(), letters.end());

        vector<string> result;
        for (auto& p : letters)
            result.emplace_back(p.second + p.first);
        for (auto& log : logs) {
            if ('0' <= log.back() && log.back() <= '9')
                result.emplace_back(log);
        }
        return result;
    }
};
