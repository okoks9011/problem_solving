#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Disjoint {
    vector<int> parent;

    Disjoint(int n) : parent(n) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u])
            return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    void uni(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v)
            parent[v] = u;
    }
};

class Solution {
  public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int max_v = 0;
        for (auto& edge : edges) {
            max_v = max(max_v, edge[0]);
            max_v = max(max_v, edge[1]);
        }

        Disjoint d(max_v+1);
        for (auto edge : edges) {
            if (d.find(edge[0]) == d.find(edge[1]))
                return edge;
            d.uni(edge[0], edge[1]);
        }
        assert(false);
    }
};
