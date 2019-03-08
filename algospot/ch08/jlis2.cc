#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const long long kNegInf = numeric_limits<long long>::min();

int CalJoinedLIS(const vector<int>& a, const vector<int>& b,
                 int i, int j,
                 vector<vector<int>>* dp_ptr) {
    auto& dp = *dp_ptr;
    auto& result = dp[i+1][j+1];
    if (result != -1)
        return result;

    long long ai = i == -1 ? kNegInf : a[i];
    long long bj = j == -1 ? kNegInf : b[j];
    long long max_v = max(ai, bj);

    result = 2;
    for (int k = i+1; k < a.size(); ++k) {
        if (max_v < a[k])
            result = max(result, 1+CalJoinedLIS(a, b, k, j, dp_ptr));
    }
    for (int k = j+1; k < b.size(); ++k) {
        if (max_v < b[k])
            result = max(result, 1+CalJoinedLIS(a, b, i, k, dp_ptr));
    }
    return result;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> b(m);
    for (auto& bj : b)
        cin >> bj;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << CalJoinedLIS(a, b, -1, -1, &dp) - 2 << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
