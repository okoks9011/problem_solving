#include <iostream>
#include <string>


using namespace std;


void Solve() {
    string s;
    int x;
    cin >> s >> x;

    string w(s.size(), '1');
    for (int i = 0; i < s.size(); ++i) {
        if (i >= x && s[i-x] == '0')
            w[i] = '0';
        if (i < s.size()-x && s[i+x] == '0')
            w[i] = '0';
    }

    string r(w.size(), '0');
    for (int i = 0; i < w.size(); ++i) {
        if (i >= x && w[i-x] == '1')
            r[i] = '1';
        if (i < w.size()-x && w[i+x] == '1')
            r[i] = '1';
    }

    if (s == r)
        cout << w << endl;
    else
        cout << -1 << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
