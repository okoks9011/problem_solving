#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int w) {
        if (n < k)
            return 0.0;
        if (k + w - 1 <= n)
            return 1.0;

        vector<double> dp(k+w);
        double sum = 0.0;
        dp[0] = 1.0;
        for (int i = 0; i < k+w-1; ++i) {
            if (i < k)
                sum += dp[i] / w;
            dp[i+1] = sum;
            if (0 <= i-w+1)
                sum -= dp[i-w+1] / w;
        }

        double result = 0.0;
        for (int i = k; i <= n; ++i)
            result += dp[i];
        return result;
    }
};
