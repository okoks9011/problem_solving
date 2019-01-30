#include <string>

using namespace std;

class ThePalindrome {
  public:
    int find(string s) {
        for (int i = s.size(); ; ++i) {
            bool flag = true;
            for (int j = 0; j < s.size(); ++j) {
                if (i-1-j < s.size() && s[j] != s[i-1-j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        // not reachable
        return 0;
    }
};
