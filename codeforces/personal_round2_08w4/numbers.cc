#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

const int kMax = 1000000000;

vector<int> primes;


int gcd(int a, int b) {
    if (b > a)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


void Solve() {
    int a, b, k;
    cin >> a >> b >> k;

    if (k == 0) {
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    int g = gcd(a, b);
    if (k == 1) {
        if (a != b && (a == g || b == g))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    int divisors = 0;
    for (int i = primes.size()-1; i >= 0; i--) {
        auto& pi = primes[i];
        while (a % pi == 0) {
            a /= pi;
            divisors++;
        }
        while (b % pi == 0) {
            b /= pi;
            divisors++;
        }
    }
    if (a != 1)
        divisors++;
    if (b != 1)
        divisors++;

    if (k <= divisors)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void InitPrimes() {
    int n = static_cast<int>(sqrt(kMax)) + 1;

    vector<char> candi(n+1, true);
    for (int i = 2; i*i <= n; i++) {
        if (!candi[i])
            continue;
        for (int j = i*i; j <= n; j += i) {
            candi[j] = false;
        }
    }
    primes = vector<int>();
    for (int i = 2; i <= n; i++) {
        if (candi[i])
            primes.emplace_back(i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    InitPrimes();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
