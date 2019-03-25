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
    int result = numeric_limits<int>::max();
    for (int i = 0; i <= n-p; ++i) {
        int cur_result = 0;
        int level = s[i];
        for (int j = 0; j < p; ++j)
            cur_result += level - s[i+j];
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
