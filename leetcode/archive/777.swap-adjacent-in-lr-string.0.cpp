class Solution {
  public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size())
            return false;

        int n = start.size();
        int si = 0;
        int ei = 0;
        while (si < n || ei < n) {
            while (si < n && start[si] == 'X')
                ++si;
            while (ei < n && end[ei] == 'X')
                ++ei;

            if (si == n || ei == n)
                break;

            if (start[si] != end[ei])
                return false;

            if (start[si] == 'L' && si < ei)
                return false;
            else if (start[si] == 'R' && si > ei)
                return false;
            ++si;
            ++ei;
        }

        return si == n && ei == n;
    }
};
