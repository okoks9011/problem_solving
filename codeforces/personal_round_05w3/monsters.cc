#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

#define ll long long


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    ll result = 0LL;
    ll min_start = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
        ll b_j = 0 < i ? b[i-1] : b[n-1];
        if (a[i] > b_j)
            result += a[i] - b_j;
        min_start = min(min_start, min(a[i], b_j));
    }
    result += min_start;
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
