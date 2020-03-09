#include <vector>
#include <cassert>


using namespace std;


class Solution {
  public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<char> visited(n+1);
        vector<double> prob(n+1);
        vector<vector<int>> adjs(n+1);
        for (auto& edge : edges) {
            int v = edge[0];
            int w = edge[1];
            adjs[v].emplace_back(w);
            adjs[w].emplace_back(v);
        }

        vector<int> cur{1};
        visited[1] = true;
        prob[1] = 1.0;
        int level = 0;
        while (!cur.empty() && level < t) {
            vector<int> next;
            for (auto& ci : cur) {
                int child_size = adjs[ci].size() - 1;
                if (ci == 1)  // root
                    ++child_size;

                for (auto& adj : adjs[ci]) {
                    if (visited[adj])
                        continue;
                    assert(child_size != 0);

                    prob[adj] = prob[ci] / child_size;
                    next.emplace_back(adj);
                    visited[adj] = true;
                }
                if (child_size)
                    prob[ci] = 0.0;
            }
            cur = next;
            ++level;
        }

        return prob[target];
    }
};
