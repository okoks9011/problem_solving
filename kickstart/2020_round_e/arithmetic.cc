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

    vector<int> diff(n-1);
    for (int i = 0; i < n-1; ++i)
        diff[i] = a[i+1] - a[i];

    int last_v = diff[0];
    int cur_len = 1;
    int max_len = 0;
    for (int i = 1; i < diff.size(); ++i) {
        if (last_v == diff[i]) {
            ++cur_len;
        } else {
            max_len = max(max_len, cur_len);
            last_v = diff[i];
            cur_len = 1;
        }
    }
    max_len = max(max_len, cur_len);

    cout << max_len + 1 << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
    }
}
