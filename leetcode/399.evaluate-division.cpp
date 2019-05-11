#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    void floyd(vector<vector<double>>* adj_ptr) {
        auto& adj = *adj_ptr;
        int n = adj.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (adj[i][k] == -1.0 || adj[k][j] == -1.0)
                        continue;
                    adj[i][j] = adj[i][k] * adj[k][j];
                }
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> idx;
        for (auto& eq : equations) {
            idx[eq[0]] = 0;
            idx[eq[1]] = 0;
        }

        int v = 0;
        for (auto& p : idx) {
            p.second = v;
            ++v;
        }

        vector<vector<double>> adj(v, vector<double>(v, -1.0));
        for (int i = 0; i < equations.size(); ++i) {
            auto& eq = equations[i];
            int a = idx[eq[0]];
            int b = idx[eq[1]];
            adj[a][b] = values[i];
            adj[b][a] = 1.0 / values[i];
        }
        floyd(&adj);

        vector<double> result;
        for (auto& q : queries) {
            auto it = idx.find(q[0]);
            if (it == idx.end()) {
                result.emplace_back(-1.0);
                continue;
            }
            int a = it->second;

            it = idx.find(q[1]);
            if (it == idx.end()) {
                result.emplace_back(-1.0);
                continue;
            }
            int b = it->second;

            result.emplace_back(adj[a][b]);
        }
        return result;
    }
};
