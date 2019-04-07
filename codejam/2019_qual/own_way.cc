#include <iostream>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    int total = 2 * n - 2;
    for (int i = 0; i < total; ++i) {
        char tmp;
        cin >> tmp;
        if (tmp == 'S')
            cout << 'E';
        else
            cout << 'S';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
