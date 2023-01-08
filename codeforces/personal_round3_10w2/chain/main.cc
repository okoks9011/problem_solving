#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i].first >> e[i].second;
    }
    sort(e.begin(), e.end());

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        a[i] = e[i].first;
        b[i] = e[i].second;
    }

    int result = n;
    vector<int> remain(n, 1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(a.begin(), a.end(), a[i]-b[i]);
        if (it != a.begin()) {
            it--;
            remain[i] += remain[it - a.begin()];
        }
        result = min(result, n-remain[i]);
    }
    cout << result << endl;
}
