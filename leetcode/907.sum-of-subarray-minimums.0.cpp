#include <vector>

using namespace std;

const int kMod = 1000000007;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        vector<int> stack;
        A.emplace_back(0);
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && A[stack.back()] >= A[i]) {
                auto j = stack.back();
                stack.pop_back();
                auto left = stack.empty() ? -1 : stack.back();
                long long cur_sum = 1LL * A[j] * (j - left) * (i - j);
                result += static_cast<int>(cur_sum % kMod);
                result %= kMod;
            }
            stack.emplace_back(i);
        }
        return result;
    }
};
