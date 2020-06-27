#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> sum_cnt(2*k+1);
    for (int i = 0; i < n/2; ++i)
        ++sum_cnt[a[i] + a[n-1-i]];

    vector<int> inter(2*k+2);
    for (int i = 0; i < n/2; ++i) {
        int start = min(a[i], a[n-1-i]) + 1;
        ++inter[start];
        int end = max(a[i], a[n-1-i]) + k;
        --inter[end+1];
    }
    for (int i = 1; i < inter.size(); ++i)
        inter[i] += inter[i-1];

    int result = n;
    for (int i = 2; i <= 2*k; ++i) {
        int cur = (inter[i] - sum_cnt[i]) + (n/2 - inter[i]) * 2;
        result = min(cur, result);
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
