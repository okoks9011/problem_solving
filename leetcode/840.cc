#include <cassert>
#include <vector>
#include <utility>


using namespace std;


class Solution {
  public:
    bool IsMagicSquare(int ci, int cj, const vector<vector<int>>& grid) {
        int sum = grid[ci-1][cj-1] + grid[ci-1][cj] + grid[ci-1][cj+1];
        for (int i = -1; i <= 1; ++i) {
            int cur = 0;
            for (int j = -1; j <= 1; ++j)
                cur += grid[ci+i][cj+j];
            if (cur != sum)
                return false;
        }
        for (int j = -1; j <= 1; ++j) {
            int cur = 0;
            for (int i = -1; i <= 1; ++i)
                cur += grid[ci+i][cj+j];
            if (cur != sum)
                return false;
        }
        if (grid[ci-1][cj-1] + grid[ci][cj] + grid[ci+1][cj+1] != sum)
            return false;
        if (grid[ci-1][cj+1] + grid[ci][cj] + grid[ci+1][cj-1] != sum)
            return false;

        vector<char> cnt(10);
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int v = grid[ci+i][cj+j];
                if (v < 0 || 9 < v)
                    return false;
                ++cnt[v];
            }
        }
        for (int i = 1; i < 10; ++i) {
            if (!cnt[i])
                return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        assert(n > 0);
        int m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;

        int result = 0;
        for (int i = 1; i < n-1; ++i) {
            for (int j = 1; j < m-1; ++j) {
                if (IsMagicSquare(i, j, grid))
                    ++result;
            }
        }
        return result;
    }
};
