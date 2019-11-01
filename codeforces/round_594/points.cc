#include <iostream>

using namespace std;


void Solve() {
    int n;
    cin >> n;
    int p_even = 0;
    int p_odd = 0;
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        if (pi % 2)
            ++p_odd;
        else
            ++p_even;
    }

    int m;
    cin >> m;
    int q_even = 0;
    int q_odd = 0;
    for (int i = 0; i < m; ++i) {
        int qi;
        cin >> qi;
        if (qi % 2)
            ++q_odd;
        else
            ++q_even;
    }

    cout << 1LL * p_odd * q_odd + 1LL * p_even * q_even << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
