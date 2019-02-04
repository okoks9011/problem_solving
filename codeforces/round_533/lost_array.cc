#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    --l;
    vector<long long> mod3(3);
    mod3[0] = (r+3)/3 - (l+3)/3;
    mod3[1] = (r+2)/3 - (l+2)/3;
    mod3[2] = (r+1)/3 - (l+1)/3;

    vector<vector<long long>> dp(n+1, vector<long long>(3));
    dp[1][0] = mod3[0];
    dp[1][1] = mod3[1];
    dp[1][2] = mod3[2];

    const int m = 1000000007;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (dp[i][j] == 0)
                continue;
            for (int k = 0; k < 3; ++k) {
                dp[i+1][(j+k)%3] += dp[i][j] * mod3[k];
                dp[i+1][(j+k)%3] %= m;
            }
        }
    }

    cout << dp[n][0] << endl;
}
