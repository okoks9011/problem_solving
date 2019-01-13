#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    const double pi = acos(-1);
    double th = pi / n;

    double R = (r * sin(th)) / (1 - sin(th));
    cout << setprecision(10);
    cout << R << endl;
}
