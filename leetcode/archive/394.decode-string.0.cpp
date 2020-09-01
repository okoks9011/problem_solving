#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
  public:
    string decodeString(string s) {
        vector<int> cnt_stack;
        vector<string> str_stack;
        string cur;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int cnt = 0;
                while (isdigit(s[i])) {
                    cnt *= 10;
                    cnt += s[i] - '0';
                    ++i;
                }
                cnt_stack.emplace_back(cnt);
                --i;
            } else if (s[i] == '[') {
                str_stack.emplace_back(cur);
                cur.clear();
            } else if (s[i] == ']') {
                string before = str_stack.back();
                str_stack.pop_back();
                int cnt = cnt_stack.back();
                cnt_stack.pop_back();

                for (int j = 0; j < cnt; ++j)
                    before += cur;
                cur = before;
            } else {
                cur += s[i];
            }
        }
        return cur;
    }
};
