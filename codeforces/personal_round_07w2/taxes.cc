#include <iostream>
#include <cmath>


using namespace std;


bool IsPrime(int n) {
    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    int result = 0;
    while (n) {
        if (IsPrime(n)) {
            ++result;
            break;
        }
        for (int i = n - 2; i > 0; --i) {
            if (IsPrime(i)) {
                n -= i;
                ++result;
                break;
            }
        }
    }
    cout << result << endl;
}
