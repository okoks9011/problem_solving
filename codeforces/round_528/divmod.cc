#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int b = k-1; b >= 1; --b) {
        if (n % b == 0) {
            cout << (n / b) * k + b << endl;
            break;
        }
    }
}
