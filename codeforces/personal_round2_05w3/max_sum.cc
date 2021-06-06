#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    vector<int> cnt(n+1);
    for (int i = 0; i < q; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        --ri;
        cnt[li] += 1;
        cnt[ri+1] -= 1;
    }

    vector<int> acc(n);
    acc[0] = cnt[0];
    for (int i = 1; i < n; ++i)
        acc[i] = acc[i-1] + cnt[i];

    sort(acc.rbegin(), acc.rend());
    sort(a.rbegin(), a.rend());
    long long result = 0LL;
    for (int i = 0; i < n; ++i)
        result += 1LL * a[i] * acc[i];
    cout << result << endl;
}
