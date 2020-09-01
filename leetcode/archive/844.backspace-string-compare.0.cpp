class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (true) {
            for (int skip = 0; i >= 0 && (S[i] == '#' || skip); --i)
                skip += S[i] == '#' ? 1 : -1;
            for (int skip = 0; j >= 0 && (T[j] == '#' || skip); --j)
                skip += T[j] == '#' ? 1 : -1;

            if (i < 0 || j < 0)
                break;

            if (S[i] != T[j]) {
                return false;
            } else {
                --i;
                --j;
            }
        }
        return i == j;
    }
};
