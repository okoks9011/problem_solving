#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        for (int j = 0; j < n; ++j) {
            cout << static_cast<char>('a' + j % k);
        }
        cout << endl;
    }
}
