#include <iostream>
#include <queue>
#include <vector>
#include <cassert>


using namespace std;


struct Elem {
    int s = 0;
    int l = 0;
    int r = 0;

    Elem(int ns, int nl, int nr) : s(ns), l(nl), r(nr) {}
};


bool operator<(const Elem& a, const Elem& b) {
    if (a.s == b.s)
        return a.l >= b.l;
    else
        return a.s < b.s;
}


void Solve() {
    int n;
    cin >> n;

    vector<int> result(n);
    priority_queue<Elem> max_q;
    max_q.emplace(n, 1, n);
    for (int i = 1; i <= n; ++i) {
        assert(!max_q.empty());
        auto e = max_q.top();
        max_q.pop();

        int mid = (e.l + e.r) / 2;
        result[mid-1] = i;

        if (e.l != e.r) {
            max_q.emplace(mid-e.l, e.l, mid-1);
            max_q.emplace(e.r-mid, mid+1, e.r);
        }
    }

    for (auto& ri : result)
        cout << ri << " ";
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        Solve();
}
