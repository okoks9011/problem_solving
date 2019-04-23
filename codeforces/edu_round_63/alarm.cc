#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> x(n);
    for (auto& xi : x)
        cin >> xi;

    long long g = 0;
    for (int i = 1; i < n; ++i)
        g = gcd(x[i]-x[i-1], g);

    for (int i = 1; i <= m; ++i) {
        long long pi;
        cin >> pi;
        if (g % pi == 0) {
            cout << "YES" << endl;
            cout << x[0] << " " << i << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
