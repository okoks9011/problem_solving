#include <iostream>


using namespace std;


void Solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << 1LL * (x2 - x1) * (y2 - y1) + 1LL << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
