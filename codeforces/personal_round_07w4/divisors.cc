#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long


using namespace std;


ll CalGCD(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return CalGCD(b, a % b);
}


ll CalLCM(ll lcm, int di) {
    ll gcd = CalGCD(lcm, di);
    return (lcm / gcd) * di;
}


void Solve() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d.begin(), d.end());

    ll lcm = d[0];
    for (int i = 1; i < n; ++i) {
        if (lcm % d[i] == 0)
            continue;
        lcm = CalLCM(lcm, d[i]);
    }
    if (lcm == d.back())
        lcm *= d[0];

    vector<int> new_d;
    for (int i = 2; i*i <= lcm; ++i) {
        if (lcm % i == 0) {
            new_d.emplace_back(i);
            if (i != lcm / i)
                new_d.emplace_back(lcm / i);
        }
    }
    sort(new_d.begin(), new_d.end());

    if (d == new_d)
        cout << lcm << endl;
    else
        cout << -1 << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
