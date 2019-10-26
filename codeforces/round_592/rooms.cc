#include <iostream>
#include <string>

using namespace std;


void Solve() {
    int n;
    cin >> n;

    string stairs;
    cin >> stairs;

    auto it = stairs.find('1');
    if (it == string::npos) {
        cout << n << endl;
        return;
    }

    auto rit = stairs.rfind('1');
    it += 1;
    if (it <= n/2)
        it = n+1 - it;
    rit += 1;
    if (rit <= n/2)
        rit = n+1 - rit;
    cout << max(it, rit) * 2 << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
