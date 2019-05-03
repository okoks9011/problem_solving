#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_map<int, int> cnt;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            auto neg = -(a[i]+a[j]);
            auto it = cnt.find(neg);
            if (it != cnt.end())
                result += it->second;
        }
        ++cnt[a[i]];
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
