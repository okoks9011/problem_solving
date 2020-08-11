#include <iostream>
#include <string>
#include <vector>


using namespace std;


void Solve() {
    string s, t;
    cin >> s >> t;

    vector<char> alpha(26);
    for (auto& si : s)
        alpha[si-'a'] = true;

    for (auto& ti : t) {
        if (!alpha[ti-'a']) {
            cout << -1 << endl;
            return;
        }
    }

    int si = 0;
    int ti = 0;
    int result = 1;
    while (ti < t.size()) {
        if (si >= s.size()) {
            si %= s.size();
            ++result;
        }

        if (s[si] == t[ti])
            ++ti;
        ++si;
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
