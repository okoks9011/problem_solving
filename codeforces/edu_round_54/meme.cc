#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

using std::sqrt;

using std::setprecision;

int main() {
    int t;
    cin >> t;
    cout << setprecision(15);
    for (int ti = 0; ti < t; ++ti) {
        int d;
        cin >> d;
        int check = d * d - 4 * d;
        if (check < 0) {
            cout << "N" << endl;
            continue;
        }

        double diff = sqrt(check);
        double a = (d + diff) / 2;
        double b = (d - diff) / 2;
        cout << "Y " << a << " " << b << endl;
    }
}
