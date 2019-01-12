#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::sort;

struct Elem {
    int l = 0;
    int r = 0;
    int idx = 0;
    Elem() = default;
    Elem(int left, int right, int index) : l(left), r(right), idx(index) {}
    bool operator<(const Elem& other) const {
        return (l < other.l);
    }
};

void Solve() {
    int n;
    cin >> n;

    vector<Elem> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].l >> segs[i].r;
        segs[i].idx = i;
    }

    sort(segs.begin(), segs.end());
    vector<int> res(n);
    vector<int> right(3);
    for (int i = 0; i < n; ++i) {
        int min_g = 1;
        if (right[2] < right[1])
            min_g = 2;
        if (right[min_g] < segs[i].l) {
            right[min_g] = segs[i].r;
            res[segs[i].idx] = min_g;
        } else {
            cout << "-1" << endl;
            return;
        }
    }

    for (auto& ri : res)
        cout << ri << " ";
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        Solve();
}
