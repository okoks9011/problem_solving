#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <sstream>

using namespace std;

struct Disjoint {
    vector<int> size;
    vector<int> parent;

    Disjoint(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    void uni(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            parent[u] = v;
            size[v] += size[u];
        }
    }

    int MaxSize() {
        return *max_element(size.begin(), size.end());
    }
};

struct Comment {
    string cmd;
    int a = 0;
    int b = 0;
};

bool Merge(Disjoint* d_ptr, int ra, int rb, int n) {
    int a = n + ra;
    int b = n + rb;
    int nota = n - ra;
    int notb = n - rb;
    auto& d = *d_ptr;
    d.uni(a, b);
    d.uni(nota, notb);

    if (d.find(a) == d.find(nota) || d.find(b) == d.find(notb))
        return false;
    else
        return true;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<Comment> comment(m);
    for (auto& c : comment) {
        cin >> c.cmd >> c.a >> c.b;
        ++c.a;
        ++c.b;
    }

    Disjoint d(2*n+1);
    for (int i = 0; i < m; ++i) {
        auto& c = comment[i];
        if (c.cmd == "ACK") {
            if (!Merge(&d, c.a, c.b, n)) {
                cout << "Contradict" << endl;
                return;
            }
        } else if (c.cmd == "DIS") {
            if (!Merge(&d, -c.a, c.b, n)) {
                cout << "Contradict" << endl;
                return;
            }
        } else {
            cerr << c.cmd << endl;
            assert(false);
        }
    }
    cout << d.MaxSize() << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
