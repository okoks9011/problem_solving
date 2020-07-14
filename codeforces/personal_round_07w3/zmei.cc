#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void Solve() {
    int n, x;
    cin >> n >> x;

    vector<int> d(n);
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i] >> h[i];

    int max_d = 0;
    int max_diff = 0;
    for (int i = 0; i < n; ++i) {
        max_d = max(max_d, d[i]);
        max_diff = max(max_diff, d[i]-h[i]);
    }

    if (max_d >= x) {
        cout << 1 << endl;
        return;
    }
    if (max_diff <= 0) {
        cout << -1 << endl;
        return;
    }
    cout << 1 + ((x-max_d)+max_diff-1) / max_diff << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
