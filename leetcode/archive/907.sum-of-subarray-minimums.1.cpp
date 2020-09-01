#include <vector>

using namespace std;

const int kMod = 1000000007;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> stack;
        vector<int> left(n);
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && A[stack.back()] >= A[i])
                stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.emplace_back(i);
        }
        stack.clear();

        vector<int> right(n);
        for (int i = n-1; i >= 0; --i) {
            while (!stack.empty() && A[stack.back()] > A[i])
                stack.pop_back();
            right[i] = stack.empty() ? n : stack.back();
            stack.emplace_back(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += static_cast<int>((1LL * (i-left[i]) * (right[i]-i) * A[i]) % kMod);
            result %= kMod;
        }
        return result;
    }
};
