#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


void dfs(int i, int j, vector<string>* grid_ptr, int* remain_ptr) {
    auto& remain = *remain_ptr;
    if (remain <= 0)
        return;

    auto& grid = *grid_ptr;
    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || n <= i || j < 0 || m <= j)
        return;
    if (grid[i][j] != '.')
        return;
    grid[i][j] = 'X';
    --remain;

    vector<pair<int, int>> ds{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    for (auto& p : ds)
        dfs(i+p.first, j+p.second, grid_ptr, remain_ptr);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    int dot_cnt = 0;
    for (auto& row : grid) {
        cin >> row;
        dot_cnt += count(row.begin(), row.end(), '.');
    }

    int remain = dot_cnt - k;
    for (int i = 0; i < grid.size(); ++i) {
        if (remain <= 0)
            break;
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '.') {
                dfs(i, j, &grid, &remain);
                break;
            }
        }
    }

    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell == 'X')
                cell = '.';
            else if (cell == '.')
                cell = 'X';
        }
    }

    for (auto& row : grid)
        cout << row << endl;
}
