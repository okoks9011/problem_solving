#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

using std::sqrt;

int main() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << endl;
        return 0;
    }

    long long p = 3;
    long long sqrt_n = sqrt(n);
    for (; p <= sqrt_n; p += 2) {
        if (n % p == 0)
            break;
    }
    if (p > sqrt_n)
        cout << 1 << endl;
    else
        cout << 1 + (n - p) / 2 << endl;
}
