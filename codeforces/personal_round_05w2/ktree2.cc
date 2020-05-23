#include <iostream>
#include <vector>


using namespace std;


const int kMod = 1000000007;


int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < d && j <= i; ++j) {
            dp[i][1] += dp[i-j][1];
            dp[i][1] %= kMod;
        }
        for (int j = d; j <= k && j <= i; ++j) {
            dp[i][1] += dp[i-j][0];
            dp[i][1] %= kMod;
        }

        for (int j = 1; j <= k && j <= i; ++j) {
            dp[i][0] += dp[i-j][0];
            dp[i][0] %= kMod;
        }
    }

    cout << dp[n][1] << endl;
}
