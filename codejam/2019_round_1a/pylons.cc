#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool Collide(int cur_i, int cur_j, int new_i, int new_j) {
    return (cur_i == new_i ||
            cur_j == new_j ||
            cur_i - cur_j == new_i - new_j ||
            cur_i + cur_j == new_i + new_j);
}

bool Fillable(int cur_i, int cur_j,
              vector<vector<int>>* grid_ptr,
              vector<pair<int, int>>* history_ptr,
              int remain) {
    auto& history = *history_ptr;
    auto& grid = *grid_ptr;
    int r = grid.size();
    int c = grid[0].size();

    grid[cur_i][cur_j] = 1;
    history.emplace_back(cur_i, cur_j);

    if (remain <= 1)
        return true;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] || Collide(cur_i, cur_j, i, j))
                continue;
            if (Fillable(i, j, grid_ptr, history_ptr, remain-1))
                return true;
        }
    }

    history.pop_back();
    grid[cur_i][cur_j] = 0;

    return false;
}

vector<pair<int, int>> Solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    vector<pair<int, int>> history;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (Fillable(i, j, &grid, &history, r*c))
                return history;
        }
    }
    return {};
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        auto s = Solve();
        if (s.empty()) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << "POSSIBLE" << endl;
            for (auto& p : s)
                cout << p.first+1 << " " << p.second+1 << endl;
        }
    }
}
