#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i-1] < a[i]) {
            dp[i][0] = 1 + dp[i-1][0];
            dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][1] + 1);
        } else {
            dp[i][0] = 1;
            dp[i][1] = dp[i-1][0] + 1;
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
        result = max({result, dp[i][0], dp[i][1]});
    cout << result << endl;
}
