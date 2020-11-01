#include <string>
#include <cassert>
#include <cctype>


using namespace std;


class Solution {
  public:
    string decodeString(string s) {
        auto it = s.begin();
        return ParseMany(&it, s);
    }

    string ParseMany(string::iterator* it_ptr, const string& s) {
        auto& it= *it_ptr;
        string cur;
        while (it != s.end() && *it != ']') {
            if (isdigit(*it)) {
                cur += ParseOne(it_ptr, s);
            } else {
                cur += *it;
                ++it;
            }
        }

        return cur;
    }

    string ParseOne(string::iterator* it_ptr, const string& s) {
        auto& it = *it_ptr;
        int cnt = 0;
        while (isdigit(*it)) {
            cnt *= 10;
            cnt += *it - '0';
            ++it;
        }
        assert(*it == '[');
        ++it;
        string body = ParseMany(it_ptr, s);
        assert(*it == ']');
        ++it;

        string cur;
        for (int i = 0; i < cnt; ++i)
            cur += body;
        return cur;
    }
};
