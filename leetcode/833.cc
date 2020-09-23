#include <vector>
#include <string>
#include <algorithm>


using namespace std;


struct Elem {
    int index = 0;
    string s;
    string t;

    bool operator<(const Elem& other) const {
        return index < other.index;
    }
};

class Solution {
  public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<Elem> rules(n);
        for (int i = 0; i < n; ++i) {
            auto& ri = rules[i];
            ri.index = indexes[i];
            ri.s = sources[i];
            ri.t = targets[i];
        }
        sort(rules.begin(), rules.end());

        string result;
        int si = 0;
        for (auto& rule : rules) {
            while (si < rule.index)
                result += S[si++];

            if (S.substr(si, rule.s.size()) == rule.s) {
                result += rule.t;
                si += rule.s.size();
            }
        }
        result += S.substr(si);
        return result;
    }
};
