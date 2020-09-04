#include <vector>


using namespace std;


class Solution {
  private:
    vector<pair<int, int>> ds;

  public:
    Solution() {
        ds = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
        };
    }

    bool dfs(int i, int j, vector<vector<char>>* grid_ptr) {
        auto& grid = *grid_ptr;
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || n <= i || j < 0 || m <= j)
            return false;
        if (grid[i][j] != '1')
            return false;
        grid[i][j] = '0';

        for (auto& d : ds)
            dfs(i+d.first, j+d.second, grid_ptr);

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, &grid))
                    ++result;
            }
        }
        return result;
    }
};
