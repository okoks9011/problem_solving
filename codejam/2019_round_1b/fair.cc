#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    vector<int> d(n);
    for (auto& di : d)
        cin >> di;

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int max_c = 0;
        int max_d = 0;
        for (int j = i; j < n; ++j) {
            max_c = max(max_c, c[j]);
            max_d = max(max_d, d[j]);
            if (abs(max_c-max_d) <= k)
                ++result;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": ";
        cout << s;
        cout << endl;
    }
}
