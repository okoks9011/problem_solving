#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int a, b, c;
    cin >> a >> b >> c;

    if (a < x) {
        cout << "NO" << endl;
        return 0;
    }

    if (a + b - x < y) {
        cout << "NO" << endl;
        return 0;
    }

    if (a + b + c - x - y < z) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
