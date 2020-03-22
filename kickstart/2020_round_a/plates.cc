#include <iostream>
#include <vector>
#include <limits>


using namespace std;


int CalMaxBeauty(int cur, int remain, int n, int k,
                 vector<vector<int>>* dp_ptr, const vector<vector<int>>& stacks) {
    if (cur == n) {
        if (remain == 0)
            return 0;
        return numeric_limits<int>::min();
    }
    auto& dp = *dp_ptr;
    auto& result = dp[cur][remain];
    if (result != -1)
        return result;

    result = numeric_limits<int>::min();
    int cur_beauty = 0;
    for (int i = 0; i <= k && i <= remain; ++i) {
        cur_beauty += i > 0 ? stacks[cur][i-1] : 0;
        result = max(result, cur_beauty + CalMaxBeauty(cur+1, remain-i, n, k, dp_ptr, stacks));
    }
    return result;
}


int Solve() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> stacks(n, vector<int>(k));
    for (auto& plates : stacks) {
        for (auto& plate : plates)
            cin >> plate;
    }

    vector<vector<int>> dp(n, vector<int>(p+1, -1));
    return CalMaxBeauty(0, p, n, k, &dp, stacks);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        cout << "Case #" << i+1 << ": " << Solve() << endl;
}
