#include <iostream>
#include <cmath>


using namespace std;


double CalValue(int i, double diff) {
    return (diff * i) / (2 * i - 1);
}


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

    int left = 1;
    int right = 1000000;
    int result = -1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        double v = CalValue(mid, diff);
        if (v <= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (abs(CalValue(result-1, diff) - target) <= abs(CalValue(result, diff) - target))
        cout << 2 * (result-1) - 1 << endl;
    else
        cout << 2 * result - 1 << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
