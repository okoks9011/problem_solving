#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int FindMinChange(int i, int j, int right, vector<int>& c, vector<vector<pair<int, int>>>* dp_ptr) {
    if (i == j)
        return 0;

    auto& dp = *dp_ptr;
    if (!right && dp[i][j].first != -1)
        return dp[i][j].first;
    else if (right && dp[i][j].second != -1)
        return dp[i][j].second;

    int result = -1;
    if (!right) {
        result = min(FindMinChange(i+1, j, 0, c, dp_ptr) + (c[i] != c[i+1]),
                     FindMinChange(i+1, j, 1, c, dp_ptr) + (c[i] != c[j]));
    } else {
        result = min(FindMinChange(i, j-1, 0, c, dp_ptr) + (c[i] != c[j]),
                     FindMinChange(i, j-1, 1, c, dp_ptr) + (c[j-1] != c[j]));
    }

    if (!right) {
        dp[i][j].first = result;
    } else {
        dp[i][j].second = result;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
    cout << min(FindMinChange(0, n-1, 0, c, &dp),
                FindMinChange(0, n-1, 1, c, &dp)) << endl;
}
