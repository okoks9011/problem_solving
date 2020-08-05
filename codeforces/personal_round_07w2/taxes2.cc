#include <iostream>


using namespace std;


bool IsPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (long long i = 2; i*i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    if (IsPrime(n)) {
        cout << 1 << endl;
        return 0;
    }
    if (n % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    if (IsPrime(n - 2)) {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
}
