#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long Solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& ai : a)
        cin >> ai;

    auto it = remove(a.begin(), a.end(), 0);
    int zero = a.end() - it;
    a.erase(it, a.end());
    sort(a.begin(), a.end());

    int non_zero = a.size();
    long long result = 0;
    vector<int> freq(200001);
    for (int i = non_zero-1; i >= 1; --i) {
        for (int j = i-1; j >= 0; --j) {
            long long mult = a[i] * a[j];
            if (mult <= 200000 && freq[mult])
                result += freq[mult];
        }
        ++freq[a[i]];
    }

    if (zero >= 2)
        result += 1LL * zero * (zero-1) / 2 * non_zero;
    if (zero >= 3)
        result += 1LL * zero * (zero-1) * (zero-2) / 6;

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
