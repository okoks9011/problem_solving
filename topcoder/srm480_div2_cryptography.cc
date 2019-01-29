#include <vector>
#include <algorithm>

using namespace std;

class Cryptography {
  public:
    long long encrypt(vector<int> numbers) {
        auto it = min_element(numbers.begin(), numbers.end());
        ++(*it);

        long long result = 1;
        for (auto& i : numbers)
            result *= i;
        return result;
    }
};
