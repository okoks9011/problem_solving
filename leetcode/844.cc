#include <string>
#include <vector>


using namespace std;


class Solution {
  public:
    string Evaluate(string s) {
        string result;
        for (auto& c : s) {
            if (c == '#') {
                if (!result.empty())
                    result.pop_back();
            } else {
                result += c;
            }
        }
        return result;
    }

    bool backspaceCompare(string S, string T) {
        return Evaluate(S) == Evaluate(T);
    }
};
