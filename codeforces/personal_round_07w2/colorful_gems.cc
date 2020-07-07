#include <iostream>
#include <set>
#include <limits>
#include <iterator>

#define ll long long


using namespace std;


set<int> ReadWeights(int n) {
    set<int> result;
    for (int i = 0; i < n; ++i) {
        int ti;
        cin >> ti;
        result.emplace(ti);
    }
    return result;
}


ll CalMinValue(const set<int>& first,
               const set<int>& second,
               const set<int>& third) {
    ll result = numeric_limits<ll>::max();
    for (auto& y : second) {
        auto fit = first.upper_bound(y);
        if (fit == first.begin())
            continue;
        --fit;
        int x = *fit;

        auto tit = third.lower_bound(y);
        if (tit == third.end())
            continue;
        int z = *tit;

        ll cur = 1LL * (x - y) * (x - y);
        cur += 1LL * (y - z) * (y - z);
        cur += 1LL * (z - x) * (z - x);
        result = min(result, cur);
    }
    return result;
}


void Solve() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;

    auto r = ReadWeights(nr);
    auto g = ReadWeights(ng);
    auto b = ReadWeights(nb);

    ll result = numeric_limits<ll>::max();
    result = min(result, CalMinValue(r, g, b));
    result = min(result, CalMinValue(r, b, g));
    result = min(result, CalMinValue(g, r, b));
    result = min(result, CalMinValue(g, b, r));
    result = min(result, CalMinValue(b, g, r));
    result = min(result, CalMinValue(b, r, g));
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
