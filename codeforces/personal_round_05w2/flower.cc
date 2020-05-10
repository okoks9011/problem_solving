// https://codeforces.com/problemset/problem/474/D
#include <iostream>
#include <vector>


using namespace std;


const int kMax = 100000;
const int kMod = 1000000007;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    vector<vector<int>> dp(kMax+1, vector<int>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= kMax; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= kMod;
        if (i - k >= 0) {
            dp[i][1] = dp[i-k][0] + dp[i-k][1];
            dp[i][1] %= kMod;
        }
    }

    vector<int> acc(kMax+1, 0);
    for (int i = 1; i <= kMax; ++i) {
        acc[i] = acc[i-1] + (dp[i][0] + dp[i][1]) % kMod;
        acc[i] %= kMod;
    }

    for (int i = 0; i < t; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        int result = acc[bi] - acc[ai-1];
        if (result < 0)
            result += kMod;
        result %= kMod;
        cout << result << endl;
    }
}
