#include <iostream>


using namespace std;


int main() {
    int t;
    long long n;
    cin >> t >> n;

    cout << (100 * n + t - 1) / t + n - 1 << endl;
}
