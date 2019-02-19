#include <iostream>
#include <vector>

using namespace std;

int CalLongestPalindromicSubseq(int i, int j, vector<int>& c, vector<int>& rc, vector<vector<int>>* dp_ptr) {
    if (i == 0 || j == 0)
        return 0;

    auto& dp = *dp_ptr;
    if (dp[i][j] != -1)
        return dp[i][j];

    int& result = dp[i][j];
    if (c[i] == rc[j]) {
        result = CalLongestPalindromicSubseq(i-1, j-1, c, rc, dp_ptr) + 1;
    } else {
        result = max(CalLongestPalindromicSubseq(i, j-1, c, rc, dp_ptr),
                     CalLongestPalindromicSubseq(i-1, j, c, rc, dp_ptr));
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    vector<int> compact;
    compact.emplace_back(c[0]);
    for (int i = 0; i < n; ++i) {
        if (compact.back() != c[i])
            compact.emplace_back(c[i]);
    }

    n = compact.size();
    vector<int> rev(compact.rbegin(), compact.rend());
    compact.insert(compact.begin(), 0);
    rev.insert(rev.begin(), 0);

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    int lps = CalLongestPalindromicSubseq(n, n, compact, rev, &dp);
    cout << n - 1 - lps/2 << endl;
}
