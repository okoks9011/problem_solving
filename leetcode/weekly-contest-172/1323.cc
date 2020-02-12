#include <string>


using namespace std;


class Solution {
  public:
    int maximum69Number (int num) {
        string s = to_string(num);
        auto it = s.find('6');
        if (it != string::npos)
            s[it] = '9';
        return stoi(s);
    }
};
