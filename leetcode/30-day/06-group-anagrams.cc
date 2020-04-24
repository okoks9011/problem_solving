#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& s : strs) {
            string key = string(s);
            sort(key.begin(), key.end());
            groups[key].emplace_back(s);
        }

        vector<vector<string>> result;
        for (auto& p : groups)
            result.emplace_back(p.second);
        return result;
    }
};
