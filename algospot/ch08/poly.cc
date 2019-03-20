#include <iostream>
#include <vector>

using namespace std;

const int kDiv = 10000000;

int CalPoly(int i, int j, vector<vector<int>>* dp_ptr) {
    auto& dp = *dp_ptr;
    if (i < 0 || dp.size() <= i || j < 0 || dp[i].size() <= j)
        return 0;
    if (i == j)
        return 1;

    auto& result = dp[i][j];
    if (result != -1)
        return result;

    result = 0;
    for (int k = 1; k <= i-j; ++k) {
        result += CalPoly(i-j, k, dp_ptr) * (j+k-1);
        result %= kDiv;
    }

    return result;
}

void Solve() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += CalPoly(n, i, &dp);
        result %= kDiv;
    }
    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
