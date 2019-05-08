#include <iostream>
#include <vector>

using namespace std;

struct Disjoint {
    vector<int> parent;

    Disjoint(int n) : parent(n) {
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
        parent[u] = v;
    }
};
