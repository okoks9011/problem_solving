#include <vector>


using namespace std;


class Solution {
  public:
    double new21Game(int n, int k, int w) {
        if (k == 0)
            return 1.0;

        vector<double> dp(k + w);
        dp[0] = 1.0;
        double sum = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = sum / w;
            if (i >= w)
                sum -= dp[i-w];
            if (i < k)
                sum += dp[i];
        }

        double result = 0.0;
        for (int i = k; i <= n && i < dp.size(); ++i)
            result += dp[i];
        return result;
    }
};
