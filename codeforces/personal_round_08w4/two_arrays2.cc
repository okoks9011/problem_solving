#include <iostream>
#include <vector>


using namespace std;


const int kMod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(2*m+1, vector<int>(n+1));
    dp[0][1] = 1;
    for (int i = 1; i <= 2*m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= kMod;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += dp[2*m][i];
        result %= kMod;
    }
    cout << result << endl;
}
