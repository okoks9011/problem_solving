#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kInf = 987654321;

int CalSegError(const vector<int>& a, int lo, int hi) {
    int result = kInf;
    for (int v = a[lo]; v <= a[hi]; ++v) {
        int error = 0;
        for (int i = lo; i <= hi; ++i)
            error += (a[i]-v) * (a[i]-v);
        result = min(result, error);
    }
    return result;
}

int CalMinError(const vector<int>& a, int s, int i,
                vector<vector<int>>* dp_ptr,
                const vector<vector<int>>& seg_error) {
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
        result = min(result, seg_error[i][j]+CalMinError(a, s-1, j+1, dp_ptr, seg_error));
    return result;
}

void Solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());

    vector<vector<int>> seg_error(n, vector<int>(n));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j < a.size(); ++j)
            seg_error[i][j] = CalSegError(a, i, j);
    }

    vector<vector<int>> dp(s+1, vector<int>(n, -1));
    cout << CalMinError(a, s, 0, &dp, seg_error) << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
