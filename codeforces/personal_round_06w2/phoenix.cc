#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    if (k == 1) {
        cout << s << endl;
        return;
    }
    if (s[0] != s[k-1] || s.size() == k) {
        cout << s[k-1] << endl;
        return;
    }

    if (s[k] == s.back()) {
        int remain = s.size() - k;
        cout << s[k-1] << string((remain + (k-1)) / k, s[k]) << endl;
    } else {
        cout << s[k-1] << s.substr(k) << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        Solve();
}
