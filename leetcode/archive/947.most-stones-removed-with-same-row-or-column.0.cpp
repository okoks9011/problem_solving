#include <vector>

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
            parent[u] = v;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Disjoint d(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                    d.uni(i, j);
            }
        }

        int comp = 0;
        for (int i = 0; i < n; ++i) {
            if (d.find(i) == i)
                ++comp;
        }
        return n - comp;
    }
};
