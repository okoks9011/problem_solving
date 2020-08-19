#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


void Solve() {
    string s, t;
    cin >> s >> t;

    vector<vector<int>> loc(26);
    for (int i = 0; i < s.size(); ++i)
        loc[s[i]-'a'].emplace_back(i);

    for (auto& ti : t) {
        if (loc[ti-'a'].empty()) {
            cout << -1 << endl;
            return;
        }
    }

    int si = 0;
    int ti = 0;
    int result = 1;
    while (ti < t.size()) {
        auto& li = loc[t[ti]-'a'];
        auto it = lower_bound(li.begin(), li.end(), si);
        if (it != li.end()) {
            ++ti;
            si = *it + 1;
        } else {
            si = 0;
            ++result;
        }
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
