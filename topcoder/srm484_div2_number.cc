#include <string>

using namespace std;

class NumberMagicEasy {
  public:
    int theNumber(string answer) {
        int result = 1;
        for (int i = 0; i < 4; ++i) {
            if (answer[3-i] != 'Y')
                result += 1 << i;
        }
        return result;
    }
};
