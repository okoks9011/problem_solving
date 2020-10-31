#include <vector>
#include <utility>


using namespace std;


class Solution {
  private:
    vector<pair<int, int>> ds;

  public:
    Solution() {
        ds = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        };
    }

    void dfs(int ci, int cj, int cost, const vector<vector<int>>& grid,
             vector<vector<int>>* dp_ptr,
             vector<pair<int, int>>* q_ptr) {
        int n = grid.size();
        int m = grid[0].size();
        if (ci < 0 || n <= ci || cj < 0 || m <= cj)
            return;
        auto& dp = *dp_ptr;
        if (dp[ci][cj] != -1)
            return;
        dp[ci][cj] = cost;
        q_ptr->emplace_back(ci, cj);
        auto d = ds[grid[ci][cj]-1];
        dfs(ci + d.first, cj + d.second, cost, grid, dp_ptr, q_ptr);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<pair<int, int>> cur;

        int cost = 0;
        dfs(0, 0, cost, grid, &dp, &cur);
        while (!cur.empty()) {
            vector<pair<int, int>> next;
            ++cost;
            for (auto& p : cur) {
                for (auto& d : ds)
                    dfs(p.first + d.first, p.second + d.second, cost, grid, &dp, &next);
            }
            cur = next;
        }
        return dp[n-1][m-1];
    }
};
