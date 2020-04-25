#include <string>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    string ReverseParen(const string& s) {
        string result(s);
        reverse(result.begin(), result.end());
        for (auto& ri : result) {
            if (ri == '(')
                ri = ')';
            else if (ri == ')')
                ri = '(';
        }
        return result;
    }

    bool checkValidOneWay(const string& s) {
        int balanced = 0;
        int star = 0;
        for (auto& si : s) {
            if (si == '(') {
                ++balanced;
            } else if (si == ')') {
                --balanced;
                if (balanced < 0) {
                    if (star <= 0)
                        return false;
                    --star;
                    ++balanced;
                }
            } else if (si == '*') {
                ++star;
            }
        }
        return balanced <= star;
    }

    bool checkValidString(string s) {
        if (s.empty())
            return true;
        return checkValidOneWay(s) && checkValidOneWay(ReverseParen(s));
    }
};
