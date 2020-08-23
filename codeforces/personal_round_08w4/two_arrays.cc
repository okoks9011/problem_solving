#include <iostream>
#include <vector>


using namespace std;


const int kMod = 1000000007;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>(n+1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= kMod;
        }
    }

    vector<int> acc(n+1);
    for (int i = 1; i <= n; ++i) {
        acc[i] = dp[m][i] + acc[i-1];
        acc[i] %= kMod;
    }

    int result = 0;
    for (int i = n; i >= 1; --i) {
        int b_cnt = dp[m][n+1-i];
        int a_acc = acc[i];
        result += (1LL * b_cnt * a_acc) % kMod;
        result %= kMod;
    }
    cout << result << endl;
}
