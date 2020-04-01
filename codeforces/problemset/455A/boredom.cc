#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


const int kMax = 100000;


long long CalMaxPoint(int i, const vector<int>& a_cnt, vector<long long>* dp_ptr) {
    if (i > kMax)
        return 0;

    auto& dp = *dp_ptr;
    auto& result = dp[i];
    if (result != -1)
        return result;

    result = max(1LL * a_cnt[i] * i + CalMaxPoint(i+2, a_cnt, dp_ptr),
                 CalMaxPoint(i+1, a_cnt, dp_ptr));
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a_cnt(kMax+1);
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++a_cnt[ai];
    }

    vector<long long> dp(kMax+1, -1);
    cout << CalMaxPoint(1, a_cnt, &dp) << endl;
}
