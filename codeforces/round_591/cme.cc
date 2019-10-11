#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;

        if (n < 4) {
            cout << 4 - n << endl;
            continue;
        }

        cout << n % 2 << endl;
    }
}
