#include <vector>
#include <iostream>
#include <cmath>

#define ll long long


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> b(n);
    for (auto& bi : b)
        cin >> bi;

    ll cur = abs(a[1]-b[1]) + 2 + (c[1]-1);
    ll result = cur;
    for (int i = 2; i < n; i++) {
        if (a[i] == b[i])
            cur = 0LL;
        int diff = abs(a[i]-b[i]);
        cur = max(cur-diff, static_cast<ll>(diff)) + 2 + c[i]-1;
        result = max(result, cur);
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
