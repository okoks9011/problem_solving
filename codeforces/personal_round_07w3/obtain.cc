#include <string>
#include <iostream>
#include <vector>


using namespace std;

const int kMax = 123456789;


int CalMinSubseq(int ti, vector<int>* dp_ptr,
                 const string s, const string t) {
    if (ti >= t.size())
        return 0;
    auto& dp = *dp_ptr;
    if (dp[ti] != -1)
        return dp[ti];

    auto& result = dp[ti];
    result = kMax;
    int ti_ori = ti;
    for (int si = 0; si < s.size() && ti < t.size(); ++si) {
        if (t[ti] == s[si]) {
            ++ti;
            auto sub_result = CalMinSubseq(ti, dp_ptr, s, t);
            cout << ti << ": " << sub_result << endl;
            if (sub_result < kMax)
                result = min(result, 1+sub_result);
        }
    }
    return result;
}


void Solve() {
    string s, t;
    cin >> s >> t;

    vector<int> dp(t.size(), -1);
    CalMinSubseq(0, &dp, s, t);
    if (dp[0] >= kMax)
        cout << -1 << endl;
    else
        cout << dp[0] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
