#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long


using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for (auto& pi : p)
        cin >> pi;

    vector<ll> acc(n);
    ll sum = 0LL;
    for (int i = 0; i < n; ++i) {
        sum += p[i];
        if (i >= m-1) {
            acc[i] = sum;
            sum -= p[i-(m-1)];
        }
    }

    vector<ll> last(n);
    for (int i = 1; i <= k; ++i) {
        vector<ll> cur(n);
        cur[m*i-1] = acc[m*i-1];
        if (i > 1)
            cur[m*i-1] += last[m*(i-1)-1];
        for (int j = m*i; j < n; ++j) {
            cur[j] = last[j-m] + acc[j];
            cur[j] = max(cur[j-1], cur[j]);
        }
        last = cur;
    }
    cout << last[n-1] << endl;
}
