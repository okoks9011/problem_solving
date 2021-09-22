#include <iostream>
#include <vector>
#include <limits>

#define ll long long


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    ll result = numeric_limits<ll>::min();
    for (int i = max(1, n - 2*k); i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            ll cur_result = 1LL*i*j - k*(a[i-1]|a[j-1]);
            result = max(result, cur_result);
        }
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
