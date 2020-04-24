#include <set>


using namespace std;


class Solution {
public:
    int next(int x) {
        int result = 0;
        while (x) {
            int d = x % 10;
            result += d * d;
            x /= 10;
        }
        return result;
    }

    bool isHappy(int n) {
        set<int> history;

        auto it = history.find(n);
        while (it == history.end()) {
            history.emplace(n);

            if (n == 1)
                return true;

            n = next(n);
            it = history.find(n);
        }

        return false;
    }
};
