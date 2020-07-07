#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    if (n > m) {
        cout << 0 << endl;
        return 0;
    }

    int result = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            result *= abs(a[i] - a[j]) % m;
            result %= m;
        }
    }
    cout << result << endl;
}
