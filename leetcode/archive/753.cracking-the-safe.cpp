#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    void genAllCandi(int n, int k, string cur, unordered_set<string>* result_ptr) {
        auto& result = *result_ptr;
        if (cur.size() == n) {
            result.emplace(cur);
            return;
        }

        for (int i = 0; i < k; ++i) {
            cur += static_cast<char>('0'+i);
            genAllCandi(n, k, cur, result_ptr);
            cur.pop_back();
        }
    }

    string FindPrefix(const string& prefix, unordered_set<string>* candi_ptr) {
        unordered_set<string>& candi = *candi_ptr;
        int n = prefix.size();
        for (auto s : candi) {
            if (s.compare(0, n, prefix) == 0) {
                candi.erase(s);
                return {s.begin()+n, s.end()};
            }
        }
        return "";
    }

    string crackSafe(int n, int k) {
        unordered_set<string> candi;
        genAllCandi(n, k, "", &candi);

        string result = *candi.begin();
        candi.erase(result);

        while (!candi.empty()) {
            for (int i = n-1; i >= 0; --i) {
                string next;
                do {
                    string suffix(result.end()-i, result.end());
                    next = FindPrefix(suffix, &candi);
                    result += next;
                } while (next.size() != 0);
            }
        }
        return result;
    }
};
