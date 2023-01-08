#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int kMax = 2000000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
    }

    int result = 0;
    for (auto& ai : a) {
        int ri = kMax;
        auto it = upper_bound(b.begin(), b.end(), ai);
        if (it != b.begin()) {
            it--;
            ri = min(ri, ai - *it);
        }
        it = lower_bound(b.begin(), b.end(), ai);
        if (it != b.end()) {
            ri = min(ri, *it - ai);
        }
        assert(ri != kMax);

        result = max(result, ri);
    }
    cout << result << endl;
}
