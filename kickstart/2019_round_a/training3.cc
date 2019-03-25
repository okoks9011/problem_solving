#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int Solve() {
    int n, p;
    cin >> n >> p;

    vector<int> s(n);
    for (auto& si : s)
        cin >> si;

    sort(s.rbegin(), s.rend());
    vector<int> acc(n);
    acc[0] = s[0];
    for (int i = 1; i < n; ++i)
        acc[i] = acc[i-1] + s[i];

    int result = numeric_limits<int>::max();
    for (int i = 0; i <= n-p; ++i) {
        int partial_sum = acc[i+p-1] - (i == 0 ? 0 : acc[i-1]);
        int cur_result = s[i] * p - partial_sum;
        result = min(result, cur_result);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
