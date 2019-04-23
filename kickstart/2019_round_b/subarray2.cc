#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int Solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int result = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> cur;
        int cur_result = 0;
        for (int j = i; j < n; ++j) {
            ++cur[a[j]];
            if (cur[a[j]] <= s) {
                ++cur_result;
            } else if (cur[a[j]] == s+1) {
                cur_result -= s;
            }
            result = max(result, cur_result);
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
