#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int FilterSum(const unordered_map<int, int>& cur, int s) {
    int result = 0;
    for (auto p : cur) {
        if (p.second > s)
            continue;
        result += p.second;
    }
    return result;
}

int Solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int result = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> cur;
        for (int j = i; j < n; ++j) {
            ++cur[a[j]];
            result = max(result, FilterSum(cur, s));
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
