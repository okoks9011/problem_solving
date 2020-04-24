#include <string>


using namespace std;


class Solution {
public:
    void compact(string& s) {
        int w = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                if (w > 0)
                    --w;
            } else {
                s[w] = s[i];
                ++w;
            }
        }
        s.erase(s.begin()+w, s.end());
    }

    bool backspaceCompare(string S, string T) {
        compact(S);
        compact(T);
        return S == T;
    }
};
