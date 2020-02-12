#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
  public:
    void rstrip(string* s_ptr) {
        auto& s = *s_ptr;
        int i = s.size()-1;
        for (; i >= 0; --i) {
            if (s[i] != ' ')
                break;
        }
        s.erase(s.begin()+i+1, s.end());
    }

    vector<string> printVertically(string s) {
        int it = 0;
        int cnt = 1;
        int max_size = 0;
        while (true) {
            int next_it = s.find(' ', it);
            if (next_it == string::npos) {
                max_size = max(max_size, static_cast<int>(s.size())-it);
                break;
            } else {
                max_size = max(max_size, next_it-it);
                ++cnt;
                it = next_it;
                ++it; // proceed to start of a aword
            }
        }

        vector<string> result(max_size, string(cnt, ' '));
        int w = 0;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                idx = 0;
                ++w;
            } else {
                result[idx][w] = s[i];
                ++idx;
            }
        }
        for (auto& s : result)
            rstrip(&s);

        return result;
    }
};
