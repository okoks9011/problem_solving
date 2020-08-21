#include <iostream>

#define ll long long


using namespace std;


int main() {
    ll u, v;
    cin >> u >> v;

    if (u > v) {
        cout << -1 << endl;
        return 0;
    }

    if (u == 0 && v == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (u == v) {
        cout << 1 << endl;
        cout << u << endl;
        return 0;
    }

    if ((v - u) % 2) {
        cout << -1 << endl;
        return 0;
    }

    ll half_diff = (v - u) / 2;
    if (half_diff + u == (half_diff ^ u)) {
        cout << 2 << endl;
        cout << half_diff << " " << (half_diff ^ u) << endl;
    } else {
        cout << 3 << endl;
        cout << half_diff << " " << half_diff << " " << u << endl;
    }
}
