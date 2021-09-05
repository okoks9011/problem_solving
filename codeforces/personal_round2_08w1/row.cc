#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long


using namespace std;


ll gcd(ll a, ll b) {
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (auto& ai : a)
        cin >> ai;
    vector<ll> b(m);
    for (auto& bi : b)
        cin >> bi;

    ll min_v = *min_element(a.begin(), a.end());
    for (auto& ai : a)
        ai -= min_v;
    a.erase(remove(a.begin(), a.end(), 0), a.end());

    ll cur = 0;
    if (a.size() > 0) {
        cur = a[0];
        for (int i = 1; i < a.size(); i++)
            cur = gcd(cur, a[i]);
    }
    for (auto& bi : b)
        cout << gcd(min_v+bi, cur) << " ";
    cout << endl;
}
