#include <iostream>
#include <string>

using namespace std;

void Solve() {
    string a;
    cin >> a;

    string b(a.size(), '0');
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '4') {
            a[i] = '3';
            b[i] = '1';
        }
    }

    int i = 0;
    while (i < b.size() && b[i] == '0')
        ++i;
    cout << a << " " << b.substr(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
