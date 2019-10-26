#include <iostream>

using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;

    int w, d;
    cin >> w >> d;

    if (n * w < p) {
        cout << -1 << endl;
        return 0;
    }

    for (long long x = p / w; x >= 0; --x) {
        long long remain = p - (x * w);
        if (remain % d == 0) {
            long long y = remain / d;
            if (x + y > n) {
                break;
            } else {
                cout << x << " " << y << " " << n - x - y << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
