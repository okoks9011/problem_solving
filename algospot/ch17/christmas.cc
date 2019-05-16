#include <iostream>
#include <vector>

using namespace std;

const int kMod = 20091101;

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> d(n);
    for (auto& di : d)
        cin >> di;

    vector<long long> acc(n);
    acc[0] = d[0];
    for (int i = 1; i < n; ++i)
        acc[i] = acc[i-1] + d[i];

    vector<int> remain(k);
    for (int i = 0; i < n; ++i)
        ++remain[acc[i]%k];

    int result = 0;
    ++remain[0];
    for (int i = 0; i < k; ++i) {
        long long cur = 1LL * remain[i] * (remain[i]-1) / 2;
        result += static_cast<int>(cur % kMod);
        result %= kMod;
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
