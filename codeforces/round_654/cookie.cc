#include <iostream>
#include <algorithm>

#define ll long long


using namespace std;


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;

        if (min(a, b) < m) {
            cout << "No" << endl;
            continue;
        }
        if (a + b < n + m)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
