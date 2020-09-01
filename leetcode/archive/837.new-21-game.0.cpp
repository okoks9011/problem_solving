#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    double new21Game(int n, int k, int w) {
        vector<double> dp(k+w);
        for (int i = k; i <= n && i < dp.size(); ++i)
            dp[i] = 1.0;

        double sum = accumulate(dp.begin()+k, dp.end(), 0.0);
        for (int i = k-1; i >= 0; --i) {
            dp[i] = sum / w;
            sum -= dp[i+w];
            sum += dp[i];
        }
        return dp[0];
    }
};
