#include <iostream>
#include <string>

using namespace std;


void Solve() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}


int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        Solve();
}
