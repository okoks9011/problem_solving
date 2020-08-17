#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void Solve() {
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    a.emplace_back(0);

    int turn = min(z, k/2);
    int base = k - turn * 2;

    int acc = a[0];
    int cur_max = a[0] + a[1];
    for (int i = 1; i <= base; ++i) {
        acc += a[i];
        cur_max = max(cur_max, a[i] + a[i+1]);
    }
    int result = acc + cur_max * turn;

    for (int x = turn-1; x >= 0; --x) {
        for (int i = 1; i <= 2; ++i) {
            int j = base + i;
            acc += a[j];
            cur_max = max(cur_max, a[j] + a[j+1]);
        }
        result = max(result, acc + cur_max * x);
        base += 2;
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
