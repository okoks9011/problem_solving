#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <limits>

#define ll long long


using namespace std;


pair<int, ll> CalStop(const vector<int>& e, const vector<int>& r,
                      ll e_sum, const vector<char>& valid) {
    int n = e.size();
    ll cur_min = 0LL;
    for (int i = 0; i < n; ++i) {
        if (!valid[i])
            continue;
        if (e_sum < e[i] + r[i])
            return {i, e_sum + cur_min};
        cur_min += e[i];
    }
    return {-1, numeric_limits<ll>::max()};
}


void Solve() {
    int n;
    cin >> n;

    vector<int> e(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
        cin >> e[i] >> r[i];

    ll e_sum = accumulate(e.begin(), e.end(), 0LL);
    vector<char> valid(n, true);

    auto p = CalStop(e, r, e_sum, valid);
    int cnt = 0;
    if (p.first == -1) {
        cout << cnt << " " << "INDEFINITELY" << endl;
        return;
    }
    valid[p.first] = false;
    e_sum -= e[p.first];

    ll max_stop = p.second;
    int update_cnt = cnt;
    while (cnt < n-1) {
        auto next = CalStop(e, r, e_sum, valid);
        ++cnt;

        if (next.first == -1) {
            cout << cnt << " " << "INDEFINITELY" << endl;
            return;
        }
        valid[next.first] = false;
        e_sum -= e[next.first];
        if (max_stop < next.second) {
            update_cnt = cnt;
            max_stop = next.second;
        }
    }
    cout << update_cnt << " " << max_stop << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
    }
}
