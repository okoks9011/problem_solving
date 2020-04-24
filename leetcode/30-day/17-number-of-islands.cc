#include <vector>


using namespace std;


class Solution {
public:
    bool dfs(int i, int j,
             const vector<vector<char>>& grid,
             vector<vector<char>>* visited_ptr, int cnt) {
        if (i < 0 || grid.size() <= i)
            return false;
        if (j < 0 || grid[i].size() <= j)
            return false;
        if (grid[i][j] != '1')
            return false;
        auto& visited = *visited_ptr;
        if (visited[i][j] != -1)
            return false;

        visited[i][j] = cnt;
        dfs(i+1, j, grid, visited_ptr, cnt);
        dfs(i-1, j, grid, visited_ptr, cnt);
        dfs(i, j+1, grid, visited_ptr, cnt);
        dfs(i, j-1, grid, visited_ptr, cnt);
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        vector<vector<char>> visited(grid.size(), vector<char>(grid[0].size(), -1));
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (dfs(i, j, grid, &visited, cnt))
                    ++cnt;
            }
        }
        return cnt;
    }
};
