#include <vector>
#include <utility>
#include <set>


using namespace std;


class Solution {
  public:
    void dfs(int cur, const vector<vector<int>>& adjs,
             vector<int>* parent_ptr) {
        auto& parent = *parent_ptr;
        for (auto& adj : adjs[cur]) {
            if (adj == parent[cur])
                continue;
            parent[adj] = cur;
            dfs(adj, adjs, parent_ptr);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjs(n);
        set<pair<int, int>> cons;
        for (auto& con : connections) {
            int u = con[0];
            int v = con[1];
            adjs[u].emplace_back(v);
            adjs[v].emplace_back(u);
            cons.emplace(u, v);
        }

        vector<int> parent(n, -1);
        dfs(0, adjs, &parent);

        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            auto it = cons.find({i, parent[i]});
            if (it == cons.end())
                ++cnt;
        }
        return cnt;
    }
};
