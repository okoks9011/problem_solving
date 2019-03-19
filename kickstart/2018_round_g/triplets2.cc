#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& ai : a)
        cin >> ai;

    sort(a.begin(), a.end());
    long long result = 0;
    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if ((a[i] * a[j] == a[k]) ||
                    (a[i] == 0 && a[j] == 0))
                    ++result;
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
