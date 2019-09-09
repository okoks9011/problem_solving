#include <iostream>
#include <vector>

using namespace std;


class DisjointSet {
  private:
    vector<int> parent;

  public:
    int cnt = 0;

    DisjointSet(int n) : parent(n), cnt(n) {
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
            --cnt;
        }
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);
    for (int i = 0; i < m; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        --c1;
        --c2;
        ds.uni(c1, c2);
    }
    int red_cnt = ds.cnt - 1;
    int total_sugar = (n-1) + red_cnt;
    cout << total_sugar;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
