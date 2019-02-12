#include <iostream>
#include <set>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

struct Envelope {
    int d = 0;
    int w = 0;
    Envelope() = default;
    Envelope(int distance, int weight) : d(distance), w(weight) {}
    bool operator<(const Envelope& other) const {
        return tie(w, d) < tie(other.w, other.d);
    }
};

long long CalMinCoin(int i, int j, int n, int m, vector<vector<long long>>* dp_ptr, vector<Envelope>& picked) {
    if (j < 0)
        return numeric_limits<long long>::max();
    if (i >= n)
        return 0;

    auto& dp = *dp_ptr;
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = min(CalMinCoin(i+1, j-1, n, m, dp_ptr, picked),
                   CalMinCoin(picked[i].d+1, j, n, m, dp_ptr, picked) + picked[i].w);
    return dp[i][j];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Envelope>> add(n+1);
    vector<vector<Envelope>> remove(n+1);
    for (int i = 0; i < k; ++i) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        --s;
        --t;
        --d;
        add[s].emplace_back(d, w);
        remove[t+1].emplace_back(d, w);
    }

    multiset<Envelope> avail;
    vector<Envelope> picked(n);
    for (int i = 0; i < n; ++i) {
        for (auto& env : add[i])
            avail.emplace(env);
        for (auto& env : remove[i])
            avail.erase(avail.find(env));

        if (!avail.empty())
            picked[i] = *avail.rbegin();
        else
            picked[i] = Envelope(i, 0);
    }

    vector<vector<long long>> dp(n, vector<long long>(m+1, -1));
    cout << CalMinCoin(0, m, n, m, &dp, picked) << endl;
}
