#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Solve() {
    int a, b;
    cin >> a >> b;
    if (a == 1 || b == 1) {
        cout << "Finite" << endl;
        return;
    }

    int lcm = a * (b / gcd(a,b));
    for (int i = a; i <= lcm; i += a) {
        for (int j = b; j <= lcm; j += b) {
            if (i - j == 1 || j - i == 1) {
                cout << "Finite" << endl;
                return;
            }
        }
    }
    cout << "Infinite" << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
