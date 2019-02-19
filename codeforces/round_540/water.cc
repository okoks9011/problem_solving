#include <iostream>

using namespace std;

void Solve() {
    long long n;
    int a, b;
    cin >> n >> a >> b;

    if (2 * a <= b)
        cout << n * a << endl;
    else
        cout << (n / 2) * b + (n % 2) * a << endl;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        Solve();
}
