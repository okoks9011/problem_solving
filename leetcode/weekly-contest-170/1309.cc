#include <vector>
#include <string>


class Solution {
public:
    string freqAlphabets(string s) {
        vector<char> buf;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '#') {
                i -= 2;
                int t = stoi(s.substr(i, 2)) + ('j'-10);
                buf.emplace_back(static_cast<char>(t));
            } else {
                buf.emplace_back(s[i] + ('a'-'1'));
            }
        }

        return {buf.rbegin(), buf.rend()};
    }
};
