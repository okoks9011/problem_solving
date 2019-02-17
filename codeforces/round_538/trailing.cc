#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

long long PrimeFactor(long long b) {
    long long sqrt_b = sqrt(b);
    for (long long i = 2; i <= sqrt_b; ++i) {
        if (b % i == 0)
            return i;
    }
    return b;
}

int main() {
    long long n, b;
    cin >> n >> b;

    unordered_map<long long, long long> fac;
    long long tmp = b;
    while (tmp > 1) {
        auto cur = PrimeFactor(tmp);
        ++fac[cur];
        tmp /= cur;
    }

    long long result = numeric_limits<long long>::max();
    for (auto& p : fac) {
        auto& prime = p.first;
        long long tmp = n;
        long long cnt = 0;
        while (tmp >= prime) {
            cnt += tmp / prime;
            tmp /= prime;
        }
        result = min(result, cnt / p.second);
    }
    cout << result << endl;
}
