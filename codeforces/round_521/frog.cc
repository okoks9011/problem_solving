#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b, k;
        cin >> a >> b >> k;

        long long result = 1LL * (a - b) * (k / 2);
        if (k & 1)
            result += a;

        cout << result << endl;
    }
}
