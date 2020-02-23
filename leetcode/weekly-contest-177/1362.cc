#include <utility>
#include <cmath>
#include <vector>


using namespace std;


class Solution {
  public:
    pair<int, int> findClosest(int n) {
        int sqrt_n = static_cast<int>(sqrt(n));
        int r = 1;
        for (int i = 1; i <= sqrt_n; ++i) {
            if (n % i == 0)
                r = i;
        }
        return {r, n / r};
    }

    vector<int> closestDivisors(int num) {
        auto p1 = findClosest(num + 1);
        auto p2 = findClosest(num + 2);

        if ((p1.second-p1.first) > (p2.second-p2.first))
            return {p2.first, p2.second};
        else
            return {p1.first, p1.second};
    }
};
