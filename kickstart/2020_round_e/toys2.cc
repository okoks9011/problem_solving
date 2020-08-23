#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <queue>

#define ll long long


using namespace std;


struct FenwickTree {
    vector<ll> buf;

    FenwickTree(ll n) : buf(n+1) {}

    void add(int x, ll v) {
        ++x;
        while (x < buf.size()) {
            buf[x] += v;
            x += (x & -x);
        }
    }

    ll sum(int x) {
        ++x;
        ll result = 0LL;
        while (x > 0) {
            result += buf[x];
            x &= (x - 1);
        }
        return result;
    }
};


void Solve() {
    int n;
    cin >> n;

    vector<int> e(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
        cin >> e[i] >> r[i];

    ll e_sum = accumulate(e.begin(), e.end(), 0LL);
    FenwickTree ft(n);
    for (int i = 0; i < n; ++i)
        ft.add(i, e[i]);

    vector<pair<ll, int>> candi(n);
    for (int i = 0; i < n; ++i) {
        candi[i].first = e[i] + r[i];
        candi[i].second = i;
    }
    sort(candi.rbegin(), candi.rend());
    int ci = 0;

    priority_queue<int, vector<int>, greater<>> min_pq;
    while (ci < n && candi[ci].first > e_sum) {
        min_pq.emplace(candi[ci].second);
        ++ci;
    }

    int cnt = 0;
    int update_cnt = cnt;
    ll last_stop = 0LL;
    while (cnt < n) {
        if (min_pq.empty()) {
            cout << cnt << " INDEFINITELY" << endl;
            return;
        }
        int ni = min_pq.top();
        min_pq.pop();

        ll part_sum = ft.sum(ni-1);
        ll cur_stop = e_sum + part_sum;
        if (cur_stop > last_stop) {
            last_stop = cur_stop;
            update_cnt = cnt;
        }

        ft.add(ni, -e[ni]);
        e_sum -= e[ni];
        ++cnt;
        while (ci < n && candi[ci].first > e_sum) {
            min_pq.emplace(candi[ci].second);
            ++ci;
        }
    }
    cout << update_cnt << " " << last_stop << endl;
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
