#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <set>
#include <limits>
#include <cassert>


using namespace std;


struct Elem {
    int idx = 0;
    int freq = 0;
    int value = 0;

    Elem(int i, int c, int v) : idx(i), freq(c), value(v) {}

    bool operator<(const Elem& other) const {
        if (idx == other.idx)
            return freq >= other.freq;
        return idx < other.idx;
    }
};


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (auto& ai : a) {
        cin >> ai;
        cnt[ai]++;
    }

    set<Elem> elems;
    for (auto& p : cnt)
        elems.emplace(-1, p.second, p.first);

    int result = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        assert(elems.size() > 0);
        auto it = elems.begin();
        Elem cur = *it;
        elems.erase(it);

        if (cur.idx != -1)
            result = min(result, i-cur.idx-1);
        if (cur.freq > 1)
            elems.emplace(i, cur.freq-1, cur.value);
    }
    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
