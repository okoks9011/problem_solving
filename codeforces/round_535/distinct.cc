#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int a = l1;
        int b = l2;

        if (a == b) {
            if (l2 != r2)
                ++b;
            else
                ++a;
        }
        cout << a << " " << b << endl;
    }
}
