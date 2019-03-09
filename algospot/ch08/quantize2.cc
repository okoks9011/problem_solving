#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

int CalSegError(const vector<int>& acc, const vector<int>& acc_sq,
                int lo, int hi) {
    int sum = acc[hi] - (lo == 0 ? 0 : acc[lo-1]);
    int m = static_cast<int>(0.5 + (sum*1.0)/(hi-lo+1));

    int sum_sq = acc_sq[hi] - (lo == 0 ? 0 : acc_sq[lo-1]);
    return (hi-lo+1) * m * m - 2 * m * sum + sum_sq;
}

int CalMinError(const vector<int>& a, int s, int i,
                vector<vector<int>>* dp_ptr,
                const vector<int>& acc, const vector<int>& acc_sq) {
    if (i == a.size())
        return 0;
    if (s == 0)
        return kInf;

    auto& dp = *dp_ptr;
    auto& result = dp[s][i];
    if (result != -1)
        return result;

    result = kInf;
    for (int j = i; j < a.size(); ++j)
        result = min(result,
                     CalSegError(acc, acc_sq, i, j)+CalMinError(a, s-1, j+1, dp_ptr, acc, acc_sq));
    return result;
}

void Solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());

    vector<int> acc(n);
    acc[0] = a[0];
    for (int i = 1; i < n; ++i)
        acc[i] = a[i] + acc[i-1];

    vector<int> acc_sq(n);
    acc_sq[0] = a[0] * a[0];
    for (int i = 1; i < n; ++i) {
        acc_sq[i] = a[i] * a[i] + acc_sq[i-1];
    }

    vector<vector<int>> dp(s+1, vector<int>(n, -1));
    cout << CalMinError(a, s, 0, &dp, acc, acc_sq) << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
