#include <string>


using namespace std;


class Solution {
  public:
    bool checkOrder(string start, string end) {
        auto sit = remove(start.begin(), start.end(), 'X');
        start.erase(sit, start.end());

        auto eit = remove(end.begin(), end.end(), 'X');
        end.erase(eit, end.end());

        return start == end;
    }

    bool canTransform(string start, string end) {
        if (start.size() != end.size())
            return false;
        int n = start.size();
        if (!checkOrder(start, end))
            return false;

        int start_l = 0;
        int start_r = 0;
        int end_l = 0;
        int end_r = 0;

        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L')
                ++start_l;
            else if (start[i] == 'R')
                ++start_r;
            if (end[i] == 'L')
                ++end_l;
            else if (end[i] == 'R')
                ++end_r;

            if (start_l > end_l || end_r > start_r)
                return false;
        }
        return true;
    }
};
