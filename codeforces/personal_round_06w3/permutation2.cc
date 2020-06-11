#include <iostream>
#include <cassert>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n/4-1; ++i) {
        int b = 4 * i;
        cout << b+2 << " " << b+4 << " " << b+1 << " " << b+3 << " ";
    }
    int b = (n/4-1) * 4;
    switch (n % 4) {
        case 0:
            cout << b+2 << " " << b+4 << " " << b+1 << " " << b+3 << " ";
            break;
        case 1:
            cout << b+2 << " " << b+4 << " " << b+1 << " " << b+3 << " " << b+5;
            break;
        case 2:
            cout << b+2 << " " << b+4 << " " << b+1 << " " << b+5 << " " << b+3 << " " << b+6;
            break;
        case 3:
            cout << b+2 << " " << b+4 << " " << b+1 << " " << b+5 << " " << b+7 << " " << b+3 << " " << b+6;
            break;
        default:
            assert(false);
            break;
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
