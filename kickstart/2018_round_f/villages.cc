#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long Solve() {
    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> villages(v, {numeric_limits<int>::max(), -1});
    for (int i = 0; i < e; ++i) {
        int f, t, w;
        cin >> f >> t >> w;
        --f;
        --t;
        villages[f] = min(villages[f], {w, t});
        villages[t] = min(villages[t], {w, f});
    }

    int free = 0;
    int z1 = -1;
    int z2 = -1;
    for (int i = 0; i < v; ++i) {
        int j = villages[i].second;
        if (villages[i].first == villages[j].first)
            ++free;
        if (villages[i].first == 0) {
            z1 = i;
            z2 = j;
        }
    }
    free /= 2;

    if (z1 != -1) {
        for (int i = 0; i < v; ++i) {
            if (villages[i].second == z1 || villages[i].second == z2)
                ++free;
        }
        free -= 2;
    }

    return 1LL << free;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
