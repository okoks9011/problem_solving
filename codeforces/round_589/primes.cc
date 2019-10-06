#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;


const long long kMod = 1000000007;


long long FastPower(long long p, long long k) {
    long long result = 1;
    p %= kMod;
    while (k > 0) {
        if (k % 2 == 0) {
            p *= p;
            p %= kMod;
            k /= 2;
        } else {
            result *= p;
            result %= kMod;
            --k;
        }
    }
    return result;
}


int main() {
    int x;
    cin >> x;
    long long n;
    cin >> n;

    unordered_set<int> primes;
    while (x > 1) {
        double sqrt_x = sqrt(x);
        int i;
        for (i = 2; i <= sqrt_x; ++i) {
            if (x % i == 0)
                break;
        }
        if (i > sqrt_x)
            i = x;
        primes.emplace(i);
        x /= i;
    }

    long long result = 1;
    for (auto& p : primes) {
        long long tmp = n / p;
        while (tmp) {
            result *= FastPower(p, tmp);
            result %= kMod;
            tmp /= p;
        }
    }
    cout << result << endl;
}
