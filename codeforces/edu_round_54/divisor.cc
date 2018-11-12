#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << endl;
        return 0;
    }

    long long p = 3;
    for (p; p <= n; p += 2) {
        if (n % p == 0)
            break;
    }
    cout << 1 + (n - p) / 2 << endl;
}
