#include <vector>
#include <algorithm>
#include <cassert>


using namespace std;


const int kInf = 12345678;

class Solution {
  public:
    void floyd(vector<vector<int>>* adjs_ptr) {
        auto& adjs = *adjs_ptr;
        int n = adjs.size();

        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < n; ++i)
                    adjs[i][j] = min(adjs[i][j], adjs[i][k] + adjs[k][j]);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjs(n, vector<int>(n, kInf));
        for (int i = 0; i < n; ++i)
            adjs[i][i] = 0;

        for (auto& edge : edges) {
            int t = edge[0];
            int f = edge[1];
            int w = edge[2];
            adjs[t][f] = w;
            adjs[f][t] = w;
        }

        floyd(&adjs);

        int max_id = -1;
        int max_n = kInf;
        for (int i = 0; i < n; ++i) {
            int cur_n = count_if(adjs[i].begin(), adjs[i].end(), [&](int v){ return v <= distanceThreshold; });
            if (cur_n <= max_n) {
                max_id = i;
                max_n = cur_n;
            }
        }
        assert(max_id != -1);

        return max_id;
    }
};
