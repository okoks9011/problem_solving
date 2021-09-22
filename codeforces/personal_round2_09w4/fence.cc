#include <iostream>
#include <vector>


using namespace std;


int CalMinHeight(int cur, vector<int>* dp_ptr, const vector<int>& h, int k) {
    auto& dp = *dp_ptr;
    int n = dp.size();

    auto& result = dp[cur];
    if (result != -1)
        return result;

    result = h[cur];
    if (cur > 0 && h[cur-1] > h[cur]) {
        int left_min = CalMinHeight(cur-1, dp_ptr, h, k);
        if (left_min == -2) {
            result = -2;
            return result;
        }
        result = max(result, left_min-k+1);
    }
    if (cur < n-1 && h[cur+1] > h[cur]) {
        int right_min = CalMinHeight(cur+1, dp_ptr, h, k);
        if (right_min == -2) {
            result = -2;
            return result;
        }
        result = max(result, right_min-k+1);
    }
    if (result - h[cur] >= k)
        result = -2;

    return result;
}


void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (auto& hi : h)
        cin >> hi;

    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        int r = CalMinHeight(i, &dp, h, k);
        if (r == -2) {
            cout << "NO" << endl;
            return;
        }
    }
    if (dp[0] != h[0] || dp[n-1] != h[n-1])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
