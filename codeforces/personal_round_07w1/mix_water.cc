#include <iostream>
#include <cmath>


using namespace std;


void Solve() {
    int h, c, t;
    cin >> h >> c >> t;

    if (h <= t) {
        cout << 1 << endl;
        return;
    } else if (t <= (h + c) / 2) {
        cout << 2 << endl;
        return;
    }

    double target = static_cast<double>(t) - static_cast<double>(c);
    double diff = static_cast<double>(h) - static_cast<double>(c);
    double cur = diff;
    int i;
    for (i = 2; cur > target; ++i)
        cur = (diff * i) / (2 * i - 1);
    --i;

    int prev_i = i - 1;
    double last = (diff * prev_i) / (2 * prev_i - 1);

    if (abs(last - target) <= abs(cur - target))
        cout << 2 * prev_i - 1 << endl;
    else
        cout << 2 * i - 1 << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
