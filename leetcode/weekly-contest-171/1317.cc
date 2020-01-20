#include <vector>
#include <cassert>

class Solution {
  public:
    bool isZeroInteger(int n) {
        if (n <= 0)
            return true;

        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            if (!isZeroInteger(i) && !isZeroInteger(n-i))
                return {i, n-i};
        }
        assert(false);
    }
};
