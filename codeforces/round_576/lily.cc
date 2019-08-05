#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double h, l;
    cin >> h >> l;

    cout << fixed << setprecision(10);
    cout << (l*l - h*h) / (2*h) << endl;
}
