#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

double CalProb(const vector<vector<int>>& grid, const vector<int>& adjs,
               int i, int j, vector<vector<double>>* dp_ptr) {
    auto& dp = *dp_ptr;
    auto& result = dp[i][j];
    if (result != -1.0)
        return result;

    int n = dp.size();
    result = 0.0;
    for (int k = 0; k < n; ++k) {
        if (grid[i][k])
            result += CalProb(grid, adjs, k, j-1, dp_ptr) / adjs[k];
    }

    return result;
}

void Solve() {
    int n, d, p;
    cin >> n >> d >> p;

    vector<vector<int>> grid(n, vector<int>(n));
    for (auto& row : grid)
        for (auto& cell : row)
            cin >> cell;

    int t;
    cin >> t;
    vector<int> q(t);
    for (auto& qi : q)
        cin >> qi;

    vector<int> adjs(n);
    for (int i = 0; i < n; ++i)
        adjs[i] = accumulate(grid[i].begin(), grid[i].end(), 0);

    vector<vector<double>> dp(n, vector<double>(d+1, -1.0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = 0.0;
    dp[p][0] = 1.0;

    for (int i = 0; i < t; ++i)
        cout << CalProb(grid, adjs, q[i], d, &dp) << " ";
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    cout << setprecision(8);
    cout << fixed;
    for (int i = 0; i < c; ++i)
        Solve();
}
