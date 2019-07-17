#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    double root = (-3 + sqrt(9 + 8.0 * (n+k))) / 2;
    cout << n - static_cast<int>(root) << endl;
}
