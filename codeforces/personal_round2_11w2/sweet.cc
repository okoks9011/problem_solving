#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    sort(a.begin(), a.end());

    vector<ll> acc(n);
    acc[0] = a[0];
    for (int i = 1; i < n; i++)
        acc[i] = acc[i-1] + a[i];

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        if (i < m) {
            b[i] = acc[i];
            continue;
        }
        b[i] = acc[i] + b[i-m];
    }
    for (auto& bi : b) {
        cout << bi << " ";
    }
    cout << endl;
}
