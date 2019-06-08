#include <vector>

using namespace std;

const long long kMod = 1000000007;

class Solution {
  public:
    int checkRecord(int n) {
        vector<long long> dp(n+1);
        vector<long long> dp_l(n+1);
        vector<long long> dp_p(n+1);

        dp_p[0] = 1;
        dp[0] = 1;
        dp_l[1] = 1;
        dp_p[1] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; ++i) {
            dp_l[i] = (dp_p[i-2] + dp_p[i-1]) % kMod;
            dp_p[i] = dp[i-1];
            dp[i] = (dp_l[i] + dp_p[i]) % kMod;
        }

        long long result = dp[n];
        for (int i = 0; i < n; ++i) {
            result += (dp[i] * dp[n-i-1]) % kMod;
            result %= kMod;
        }
        return static_cast<int>(result);
    }
};
