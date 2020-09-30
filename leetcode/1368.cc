#include <vector>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>


using namespace std;


const int kMax = 987654321;

struct Elem {
    int i = 0;
    int j = 0;
    int len = 0;

    Elem(int ni, int nj, int nlen) : i(ni), j(nj), len(nlen) {}

    bool operator>(const Elem& other) const {
        return len > other.len;
    }
};

class Solution {
  public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        assert(m > 0);
        int n = grid[0].size();

        vector<vector<int>> path(m, vector<int>(n, kMax));
        path[0][0] = 0;
        priority_queue<Elem, vector<Elem>, greater<>> min_q;
        min_q.emplace(0, 0, 0);

        vector<pair<int, int>> ds{
            {0, 0}, // dummy
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        while (!min_q.empty()) {
            auto e = min_q.top();
            min_q.pop();
            if (e.len > path[e.i][e.j])
                continue;
            for (int x = 1; x <= 4; ++x) {
                int nlen = e.len;
                if (grid[e.i][e.j] != x)
                    ++nlen;
                int ni = e.i + ds[x].first;
                int nj = e.j + ds[x].second;
                if (ni < 0 || m <= ni || nj < 0 || n <= nj)
                    continue;
                if (path[ni][nj] > nlen) {
                    path[ni][nj] = nlen;
                    min_q.emplace(ni, nj, nlen);
                }
            }
        }
        return path[m-1][n-1];
    }
};
