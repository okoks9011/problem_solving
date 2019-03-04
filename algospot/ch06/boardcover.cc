#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool Place(int i, int j, const vector<pair<int, int>>& b, vector<string>* grid_ptr) {
    auto& grid = *grid_ptr;
    for (auto& bi : b) {
        int new_i = i+bi.first;
        int new_j = j+bi.second;
        if (new_i < 0 || grid.size() <= new_i ||
            new_j < 0 || grid[new_i].size() <= new_j)
            return false;
        if (grid[new_i][new_j] == '#')
            return false;
    }

    for (auto& bi : b)
        grid[i+bi.first][j+bi.second] = '#';
    return true;
}

void Unplace(int i, int j, const vector<pair<int, int>>& b, vector<string>* grid_ptr) {
    auto& grid = *grid_ptr;
    for (auto& bi : b)
        grid[i+bi.first][j+bi.second] = '.';
}

int CountPlace(int remain, vector<string>* grid_ptr) {
    if (remain == 0)
        return 1;

    vector<vector<pair<int, int>>> blocks{
        {{0, 0}, {1, -1}, {1, 0}},
        {{0, 0}, {0, 1}, {1, 0}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}}
    };

    auto& grid = *grid_ptr;
    int pi = -1;
    int pj = -1;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] != '#') {
                pj = j;
                break;
            }
        }
        if (pj != -1) {
            pi = i;
            break;
        }
    }

    int result = 0;
    for (auto& b : blocks) {
        if (!Place(pi, pj, b, grid_ptr))
            continue;
        result += CountPlace(remain-1, grid_ptr);
        Unplace(pi, pj, b, grid_ptr);
    }

    return result;
}

void Solve() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i)
        cin >> grid[i];

    int cnt = 0;
    for (auto& row : grid)
        cnt += count(row.begin(), row.end(), '.');
    if (cnt % 3) {
        cout << "0" << endl;
        return;
    }

    cout << CountPlace(cnt/3, &grid) << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
