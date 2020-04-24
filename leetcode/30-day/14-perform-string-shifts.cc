#include <vector>


using namespace std;


class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total = 0;
        for (auto& v : shift) {
            if (v[0])
                total -= v[1];
            else
                total += v[1];
        }
        total += s.size() * 100 * 100;
        total %= s.size();

        return s.substr(total) + s.substr(0, total);
    }
};
