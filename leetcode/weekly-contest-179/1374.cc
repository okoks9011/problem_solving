#include <string>


using namespace std;


class Solution {
  public:
    string generateTheString(int n) {
        string result(n, 'a');
        if (n % 2 == 0)
            result.back() = 'b';

        return result;
    }
};
