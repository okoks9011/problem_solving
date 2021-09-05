#include <iostream>
#include <vector>


using namespace std;


int CalMaxGood(int cur, int t, vector<vector<int>>* dp_ptr,
               const vector<int>& a, int l, int r) {
    auto& dp = *dp_ptr;
    int n = dp.size();
    if (cur >= n)
        return 0;
    int h = dp[0].size();

    auto& result = dp[cur][t];
    if (result != -1)
        return result;

    for (int i = 0; i <= 1; i++) {
        int ri = 0;
        int next_t = (t+a[cur]-i) % h;
        if (l <= next_t && next_t <= r)
            ri++;
        ri += CalMaxGood(cur+1, next_t, dp_ptr, a, l, r);
        result = max(result, ri);
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<vector<int>> dp(n, vector<int>(h, -1));
    cout << CalMaxGood(0, 0, &dp, a, l, r) << endl;
}
