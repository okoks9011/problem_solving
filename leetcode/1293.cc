#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>


using namespace std;

struct Elem {
    int i = 0;
    int j = 0;
    int t = 0;

    Elem(int ni, int nj, int nt) : i(ni), j(nj), t(nt) {}
};

const int kMax = 987654321;

class Solution {
  public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        assert(n > 0);

        int m = grid[0].size();
        if (k >= m + n - 3)
            return m + n - 2;

        vector<pair<int, int>> ds{
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        vector<Elem> cur;
        visited[0][0][k] = 0;
        cur.emplace_back(0, 0, k);

        int level = 1;
        while (!cur.empty()) {
            vector<Elem> next;
            for (auto& p : cur) {
                for (auto& d : ds) {
                    int ni = p.i + d.first;
                    int nj = p.j + d.second;
                    if (ni < 0 || n <= ni || nj < 0 || m <= nj)
                        continue;
                    if (grid[ni][nj] == 0) {
                        if (visited[ni][nj][p.t] != -1)
                            continue;
                        visited[ni][nj][p.t] = level;
                        next.emplace_back(ni, nj, p.t);
                    } else if (grid[ni][nj] == 1 && p.t > 0) {
                        if (visited[ni][nj][p.t-1] != -1)
                            continue;
                        visited[ni][nj][p.t-1] = level;
                        next.emplace_back(ni, nj, p.t-1);
                    }
                }
            }
            cur = next;
            ++level;
        }

        int result = kMax;
        for (auto& r : visited[n-1][m-1]) {
            if (r == -1)
                continue;
            result = min(result, r);
        }
        if (result == kMax)
            return -1;
        else
            return result;
    }
};
