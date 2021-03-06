#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long


using namespace std;


const ll kInf = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    vector<string> words(n);
    vector<string> words_rev(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        words_rev[i] = string(words[i].rbegin(), words[i].rend());
    }

    vector<vector<ll>> dp(n, vector<ll>(2, kInf));
    dp[0][0] = 0LL;
    dp[0][1] = c[0];

    for (int i = 1; i < n; ++i) {
        if (words[i-1] <= words[i])
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if (words_rev[i-1] <= words[i])
            dp[i][0] = min(dp[i][0], dp[i-1][1]);

        if (words[i-1] <= words_rev[i])
            dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if (words_rev[i-1] <= words_rev[i])
            dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);

        if (dp[i][0] >= kInf && dp[i][1] >= kInf) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}
