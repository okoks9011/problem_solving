#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s[0] != '1' || s.back() != '1') {
        cout << "NO" << endl;
        return;
    }
    if (s.size() % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    int ones = count(s.begin(), s.end(), '1');
    if (ones % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    int cur_ones = 0;
    bool open_a = true;
    string a(s.size(), ' ');
    string b(s.size(), ' ');
    for (int i = 0; i < a.size(); ++i) {
        if (s[i] == '1') {
            if (cur_ones < ones / 2) {
                a[i] = '(';
                b[i] = '(';
            } else {
                a[i] = ')';
                b[i] = ')';
            }
            cur_ones++;
        } else if (s[i] == '0') {
            if (open_a) {
                a[i] = '(';
                b[i] = ')';
            } else {
                a[i] = ')';
                b[i] = '(';
            }
            open_a = !open_a;
        } else {
            assert(false);
        }
    }
    cout << "YES" << endl;
    cout << a << endl;
    cout << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
