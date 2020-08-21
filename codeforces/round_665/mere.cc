#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int min_v = *min_element(a.begin(), a.end());
    vector<int> m;
    for (int i = 0; i < n; ++i) {
        if (a[i] % min_v != 0)
            continue;
        m.emplace_back(a[i]);
        a[i] = -1;
    }
    sort(m.begin(), m.end());

    int mi = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1)
            continue;
        a[i] = m[mi];
        ++mi;
    }

    for (int i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
