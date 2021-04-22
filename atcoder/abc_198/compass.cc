#include <iostream>
#include <cmath>


using namespace std;


int main() {
    long long r, x, y;
    cin >> r >> x >> y;

    double d = sqrt(x * x + y * y) / r;
    if (d < 1.0)
        cout << 2 << endl;
    else
        cout << static_cast<int>(ceil(d)) << endl;
}
