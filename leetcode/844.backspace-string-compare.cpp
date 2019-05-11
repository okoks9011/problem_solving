#include <string>

using namespace std;

class Solution {
public:
    string compact(const string& t) {
        string result;
        for (auto& ti : t) {
            if (ti == '#') {
                if (!result.empty())
                    result.pop_back();
            } else {
                result += ti;
            }
        }
        return result;
    }

    bool backspaceCompare(string S, string T) {
        return compact(S) == compact(T);
    }
};
