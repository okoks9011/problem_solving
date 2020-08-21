#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long


using namespace std;


const int kMod = 1000000007;


int CountSize(int cur, int parent,
              const vector<vector<int>>& adjs,
              vector<int>* cnt_ptr) {
    int cur_size = 1;
    for (auto v : adjs[cur]) {
        if (v == parent)
            continue;
        cur_size += CountSize(v, cur, adjs, cnt_ptr);
    }

    int n = adjs.size();
    auto& cnt = *cnt_ptr;
    cnt[cur] = ((1LL * cur_size) * (n - cur_size)) % kMod;
    return cur_size;
}


void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjs(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u].emplace_back(v);
        adjs[v].emplace_back(u);
    }

    int m;
    cin >> m;

    vector<int> pf(m);
    for (auto& pi : pf)
        cin >> pi;
    sort(pf.rbegin(), pf.rend());

    int t = n - 1;
    vector<int> candi(t, 1);
    int diff = m - t;
    if (diff > 0) {
        for (int i = 0; i < m; ++i) {
            int ci = max(0, i - diff);
            ll tmp = 1LL * candi[ci] * pf[i];
            tmp %= kMod;
            candi[ci] = static_cast<int>(tmp);
        }
    } else {
        for (int i = 0; i < m; ++i)
            candi[i] = pf[i];
    }

    vector<int> cnt(n);
    CountSize(0, -1, adjs, &cnt);
    sort(cnt.rbegin(), cnt.rend());
    cnt.pop_back();

    ll result = 0;
    for (int i = 0; i < t; ++i) {
        result += 1LL * candi[i] * cnt[i];
        result %= kMod;
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
