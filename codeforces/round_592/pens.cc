#include <iostream>

using namespace std;


void Solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int pens = (a + c-1) / c;
    int pencils = (b + d-1) / d;

    if (pens + pencils > k) {
        cout << -1 << endl;
        return;
    }
    cout << pens << " " << pencils << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
