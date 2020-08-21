#include <iostream>
#include <algorithm>


using namespace std;


void Solve() {
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;

    int plus = min(z1, y2);
    int remain01 = (y2 - plus) + x2;
    int minus = min(y1 - min(y1, remain01), z2);
    cout << 2 * plus - 2 * minus << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
