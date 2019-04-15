#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long CountUnique(long long w,
                      const vector<long long>& d,
                      const vector<long long>& acc) {
    auto p = lower_bound(d.begin(), d.end(), w) - d.begin() - 1;
    long long result = 0;
    if (p >= 0)
        result += acc[p];
    result += (acc.size()-p) * w;
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<long long> s(n);
    for (auto& si : s)
        cin >> si;
    sort(s.begin(), s.end());

    int q;
    cin >> q;

    vector<long long> w(q);
    for (int i = 0; i < q; ++i) {
        long long lk, rk;
        cin >> lk >> rk;
        w[i] = rk - lk + 1;
    }

    vector<long long> d(n-1);
    for (int i = 0; i < n-1; ++i)
        d[i] = s[i+1] - s[i];
    sort(d.begin(), d.end());

    vector<long long> acc(n-1);
    if (n > 1)
        acc[0] = d[0];
    for (int i = 1; i < n-1; ++i)
        acc[i] = acc[i-1] + d[i];

    for (int i = 0; i < q; ++i)
        cout << CountUnique(w[i], d, acc) << " ";
    cout << endl;
}
