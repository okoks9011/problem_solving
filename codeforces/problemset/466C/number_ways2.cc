#include <iostream>
#include <vector>
#include <numeric>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto& ai : a)
        cin >> ai;

    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    long long t1 = sum / 3;
    long long t2 = t1 * 2;

    int cnt = 0;
    long long acc = 0;
    long long result = 0;
    for (int i = 0; i < n-1; ++i) {
        acc += a[i];
        if (acc == t2)
            result += cnt;
        if (acc == t1)
            ++cnt;
    }

    cout << result << endl;
}
