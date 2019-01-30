#include <string>

using namespace std;

class ThePalindrome {
  public:
    bool check(string s) {
        int last = s.size()-1;
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[last-i])
                return false;
        }
        return true;
    }

    int find(string s) {
        if (check(s))
            return s.size();

        for (int i = 1; i <= s.size(); ++i) {
            string subs = s.substr(0, i);
            string tmp(s);
            tmp.append(subs.rbegin(), subs.rend());
            if (check(tmp))
                return tmp.size();
        }
        // not reachable
        return 0;
    }
};
