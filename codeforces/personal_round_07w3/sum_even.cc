#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<ll> dp1(n/2);
    for (int i = 0; i < n/2; ++i) {
        dp1[i] = a[2*i+1] - a[2*i];
        if (i > 0 && dp1[i-1] > 0)
            dp1[i] += dp1[i-1];
    }

    vector<ll> dp2((n-1)/2);
    for (int i = 0; i < (n-1)/2; ++i) {
        dp2[i] = a[2*i+1] - a[2*i+2];
        if (i > 0 && dp2[i-1] > 0)
            dp2[i] += dp2[i-1];
    }

    ll max_diff = 0LL;
    for (auto& d : dp1)
        max_diff = max(max_diff, d);
    for (auto& d : dp2)
        max_diff = max(max_diff, d);

    ll result = 0LL;
    for (int i = 0; i < n; i += 2)
        result += a[i];
    result += max_diff;

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
