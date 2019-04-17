#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2) {
        cout << ":(" << endl;
        return 0;
    }

    vector<int> cnt(2);
    cnt[0] = count(s.begin(), s.end(), '(');
    cnt[1] = count(s.begin(), s.end(), ')');
    if (cnt[0] > n/2 || cnt[1] > n/2) {
        cout << ":(" << endl;
        return 0;
    }

    cnt[0] = (n/2) - cnt[0];
    cnt[1] = (n/2) - cnt[1];
    for (auto& si : s) {
        if (si != '?')
            continue;

        if (cnt[0]) {
            si = '(';
            --cnt[0];
        } else if (cnt[1]) {
            si = ')';
            --cnt[1];
        } else {
            assert(false);
        }
    }

    vector<int> cur(2);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++cur[0];
        } else if (s[i] == ')') {
            ++cur[1];
        } else {
            assert(false);
        }

        if (i != n-1 && cur[0] <= cur[1]) {
            cout << ":(" << endl;
            return 0;
        }
    }

    cout << s << endl;
}
