#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <limits>
#include <cmath>

using namespace std;

bool CanRemove(const vector<vector<int>>& grid, int k) {
    int r = grid.size();
    int c = grid[0].size();

    int sum_min = numeric_limits<int>::max();
    int sum_max = numeric_limits<int>::min();
    int diff_min = numeric_limits<int>::max();
    int diff_max = numeric_limits<int>::min();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] <= k)
                continue;
            int sum = i + j;
            sum_min = min(sum_min, sum);
            sum_max = max(sum_max, sum);
            int diff = i - j;
            diff_min = min(diff_min, diff);
            diff_max = max(diff_max, diff);
        }
    }

    if (sum_min == numeric_limits<int>::max())
        return true;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int sum = i + j;
            int diff = i - j;
            if (abs(sum-sum_min) <= k &&
                abs(sum-sum_max) <= k &&
                abs(diff-diff_min) <= k &&
                abs(diff-diff_max) <= k)
                return true;
        }
    }
    return false;
}

void bfs(deque<pair<int, int>> q, vector<vector<int>>* grid_ptr) {
    auto& grid = *grid_ptr;

    vector<pair<int, int>> ds{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        for (auto& d : ds) {
            int new_i = p.first + d.first;
            int new_j = p.second + d.second;
            if (new_i < 0 || grid.size() <= new_i ||
                new_j < 0 || grid[0].size() <= new_j)
                continue;

            int new_t = grid[p.first][p.second] + 1;
            if (grid[new_i][new_j] <= new_t)
                continue;

            grid[new_i][new_j] = new_t;
            q.emplace_back(new_i, new_j);
        }
    }
}

int Solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c, r+c));
    deque<pair<int, int>> q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char tmp;
            cin >> tmp;
            if (tmp == '0')
                continue;
            q.emplace_back(i, j);
            grid[i][j] = 0;
        }
    }
    bfs(q, &grid);

    int left = 0;
    int right = r + c - 2;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (CanRemove(grid, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
