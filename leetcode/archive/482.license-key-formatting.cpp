#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string normal(S);
        normal.erase(remove(normal.begin(), normal.end(), '-'), normal.end());
        reverse(normal.begin(), normal.end());

        string result;
        int chunks = (normal.size()+K-1) / K;
        for (int i = 0; i < chunks; ++i) {
            string cur = normal.substr(i*K, K);
            for (auto& c : cur)
                c = toupper(c);
            result += cur;
            if (i != chunks-1)
                result += '-';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
