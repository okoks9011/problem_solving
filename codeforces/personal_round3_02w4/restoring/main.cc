#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <cassert>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> q(n);
    for (auto& qi : q)
        cin >> qi;

    vector<int> skel_p(q.size(), 0);
    set<int> remain;
    for (int i = 1; i <= n; i++)
        remain.emplace(i);
    for (int i = 0; i < n; i++) {
        if (i == 0 || q[i-1] < q[i]) {
            skel_p[i] = q[i];
            remain.erase(q[i]);
        }
    }

    vector<int> min_p(skel_p);
    set<int> min_remain(remain);
    for (auto& pi : min_p) {
        if (pi != 0)
            continue;
        assert(min_remain.size() != 0);
        auto min_it = min_remain.begin();
        pi = *min_it;
        min_remain.erase(min_it);
    }

    vector<int> max_p(skel_p);
    set<int> max_remain(remain);
    for (int i = 0; i < n; i++) {
        auto& pi = max_p[i];
        if (pi != 0)
            continue;
        assert(max_remain.size() != 0);
        auto max_it = max_remain.lower_bound(q[i]);
        assert(max_it != max_remain.begin());
        max_it--;
        pi = *max_it;
        max_remain.erase(max_it);
    }

    for (auto& pi : min_p)
        cout << pi << " ";
    cout << endl;
    for (auto& pi : max_p)
        cout << pi << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        Solve();
    }
}
