#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> h(n);
    for (auto& hi : h)
        cin >> hi;

    int bag = m;
    for (int i = 0; i < n-1; ++i) {
        int target = max(0, h[i+1] - k);
        if (h[i] >= target) {
            bag += h[i] - target;
        } else {
            int need = target - h[i];
            if (bag >= need) {
                bag -= need;
            } else {
                cout << "NO" << endl;
                return;
            }
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
