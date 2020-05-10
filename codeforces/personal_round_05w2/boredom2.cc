// https://codeforces.com/problemset/problem/455/A
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


const int kMax = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(kMax+1);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++cnt[ai];
    }

    vector<long long> dp(kMax+1);
    dp[0] = 0;
    dp[1] = cnt[1];
    for (int i = 2; i <= kMax; ++i)
        dp[i] = max(dp[i-1], 1LL*i*cnt[i] + dp[i-2]);
    cout << dp[kMax] << endl;
}
