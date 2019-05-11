#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Disjoint {
    vector<int> parent;
    vector<int> size;
    vector<int> enermy;

    Disjoint(int n) : parent(n), size(n, 1), enermy(n, -1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    int uni(int u, int v) {
        if (u == -1 || v == -1)
            return max(u, v);

        u = find(u);
        v = find(v);
        if (u != v) {
            parent[u] = v;
            size[v] += size[u];
        }
        return v;
    }

    bool ack(int u, int v) {
        u = find(u);
        v = find(v);
        if (enermy[u] == v)
            return false;

        int a = uni(u, v);
        int b = uni(enermy[u], enermy[v]);
        enermy[a] = b;
        if (b != -1)
            enermy[b] = a;
        return true;
    }

    bool dis(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;

        int a = uni(u, enermy[v]);
        int b = uni(enermy[u], v);
        enermy[a] = b;
        enermy[b] = a;
        return true;
    }
};

struct Cmt {
    string cmd;
    int a = -1;
    int b = -1;
};

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<Cmt> cmt(m);
    for (auto& ci : cmt)
        cin >> ci.cmd >> ci.a >> ci.b;

    Disjoint d(n);
    for (int i = 0; i < m; ++i) {
        auto& ci = cmt[i];
        if (ci.cmd == "ACK") {
            if (!d.ack(ci.a, ci.b)) {
                cout << "CONTRADICTION AT " << i+1 << endl;
                return;
            }
        } else if (ci.cmd == "DIS") {
            if (!d.dis(ci.a, ci.b)) {
                cout << "CONTRADICTION AT " << i+1 << endl;
                return;
            }
        } else {
            cerr << ci.cmd << endl;
            assert(false);
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int ei = d.enermy[i];
        if (i != d.parent[i] || i < ei)
            continue;

        int enermy_size = ei == -1 ? 0 : d.size[ei];
        result += max(d.size[i], enermy_size);
    }
    cout << "MAX PARTY SIZE IS " << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
