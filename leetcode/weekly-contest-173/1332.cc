#include <string>


using namespace std;


class Solution {
  public:
    int removePalindromeSub(string s) {
        if (s.size() == 0)
            return 0;

        int n = s.size();
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[n-1-i])
                return 2;
        }
        return 1;
    }
};
