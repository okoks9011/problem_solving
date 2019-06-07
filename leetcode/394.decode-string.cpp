#include <string>
#include <cctype>

using namespace std;

class Solution {
  public:
    string decode(const string& s, int* i_ptr) {
        auto& i = *i_ptr;
        string result;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int cnt = 0;
                while (isdigit(s[i])) {
                    cnt *= 10;
                    cnt += s[i] - '0';
                    ++i;
                }

                ++i;  // skip [
                auto cur = decode(s, i_ptr);
                for (int j = 0; j < cnt; ++j)
                    result += cur;
            } else {
                result += s[i];
            }
            ++i;
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, &i);
    }
};
