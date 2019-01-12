#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int Minimum(int l, int r, int d) {
    if (d < l || r < d)
        return d;
    return ((r/d)+1)*d;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r, d;
        cin >> l >> r >> d;

        cout << Minimum(l, r, d) << endl;;
    }
}
