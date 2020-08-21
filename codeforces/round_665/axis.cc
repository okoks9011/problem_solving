#include <iostream>


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    if (n < k) {
        cout << k - n << endl;
        return;
    }
    if ((n - k) % 2)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
