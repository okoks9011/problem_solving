#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int x;
    cin >> x;

    x %= 4;
    switch (x) {
        case 0: {
            cout << "1 A" << endl;
            break;
        }
        case 1: {
            cout << "0 A" << endl;
            break;
        }
        case 2: {
            cout << "1 B" << endl;
            break;
        }
        case 3: {
            cout << "2 A" << endl;
            break;
        }
        default: {
            assert(false);
        }
    }
}
