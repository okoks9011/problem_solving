#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int LIMIT = 10000000;

vector<int> getPrimes() {
    vector<char> candis(LIMIT+1, true);
    candis[0] = false;
    candis[1] = false;
    for (int i = 2; i*i <= LIMIT; i++) {
        if (!candis[i]) {
            continue;
        }
        for (int j = i*i; j <= LIMIT; j += i) {
            candis[j] = false;
        }
    }

    vector<int> result;
    for (int i = 2; i < candis.size(); i++) {
        if (candis[i]) {
            result.emplace_back(i);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    for (auto& xi : x) {
        cin >> xi;
    }

    auto primes = getPrimes();

    vector<int> counts(LIMIT+1);
    for (auto& xi : x) {
        counts[xi]++;
    }

    vector<int> pre(primes.size());
    for (int i = 0; i < primes.size(); i++) {
        auto pi = primes[i];
        for (int pj = pi; pj <= LIMIT; pj += pi) {
            pre[i] += counts[pj];
        }
    }

    vector<int> acc(primes.size()+1);
    for (int i = 0; i < primes.size(); i++) {
        acc[i+1] = acc[i] + pre[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int li, ri;
        cin >> li >> ri;

        auto it = lower_bound(primes.begin(), primes.end(), li);
        int lpi = it - primes.begin();

        it = lower_bound(primes.begin(), primes.end(), ri+1);
        int rpi = it - primes.begin();

        cout << acc[rpi] - acc[lpi] << endl;
    }
}
