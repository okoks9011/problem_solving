#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Seg {
    int l = 0;
    int r = 0;
    int i = 0;

    bool operator<(const Seg& other) const {
        return r < other.r;
    }
};

void Solve() {
    int n;
    cin >> n;

    vector<Seg> segs(n);
    for (int i = 0; i < n; ++i) {
        segs[i].i = i;
        cin >> segs[i].l >> segs[i].r;
    }

    sort(segs.begin(), segs.end());

    vector<int> result(n, 1);
    auto rit = segs.rbegin();
    auto last = *rit;
    result[last.i] = 2;
    int min_l = last.l;

    ++rit;
    while (rit != segs.rend()) {
        if (rit->r < min_l) {
            for (auto& r : result)
                cout << r << " ";
            cout << endl;
            return;
        }
        result[rit->i] = 2;
        min_l = min(min_l, rit->l);
        ++rit;
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i)
        Solve();
}
