#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s.size() == 2 && s[0] >= s[1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s[0] << " " << s.substr(1) << endl;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        solve();
}
