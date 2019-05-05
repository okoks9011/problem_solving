#include <algorithm>
#include <limits>

using namespace std;

const int kMod = 1000000007;

class Solution {
  public:
    int sumSubarrayMins(vector<int>& A) {
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            int cur_min = numeric_limits<int>::max();
            for (int j = i; j < A.size(); ++j) {
                cur_min = min(cur_min, A[j]);
                result += cur_min;
                result %= kMod;
            }
        }
        return result;
    }
};
