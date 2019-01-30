#include <vector>

using namespace std;

class InterestingDigits {
  public:
    vector<int> digits(int base) {
        vector<int> result;
        int maximum = base * base * base * base;
        for (int i = 2; i < base; ++i) {
            bool flag = true;
            for (int j = i; j < maximum; j += i) {
                int tmp = j;
                int sum = 0;
                while (tmp) {
                    sum += tmp % base;
                    tmp /= base;
                }
                if (sum % i != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                result.emplace_back(i);
        }

        return result;
    }
};
