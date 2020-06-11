#include <iostream>


using namespace std;


void Solve() {
    int n, x;
    cin >> n >> x;

    int neighbors_x = 0;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == x || v == x)
            ++neighbors_x;
    }

    if (neighbors_x <= 1 || n % 2 == 0)
        cout << "Ayush" << endl;
    else
        cout << "Ashish" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
