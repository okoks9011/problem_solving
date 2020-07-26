#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;


const vector<pair<int, int>> ds{
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void bfs(vector<string>* grid_ptr) {
    auto& grid = *grid_ptr;
    int n = grid.size();
    int m = grid[0].size();
    if (grid[n-1][m-1] == '#')
        return;

    vector<pair<int, int>> q;
    grid[n-1][m-1] = '#';
    q.emplace_back(n-1, m-1);

    while (!q.empty()) {
        vector<pair<int, int>> next_q;
        for (auto& e : q) {
            for (auto& d : ds) {
                int ui = e.first + d.first;
                int uj = e.second + d.second;
                if (ui < 0 || n <= ui || uj < 0 || m <= uj)
                    continue;
                if (grid[ui][uj] == '#' || grid[ui][uj] == 'B')
                    continue;
                grid[ui][uj] = '#';
                next_q.emplace_back(ui, uj);
            }
        }
        q = next_q;
    }
}


bool CanBlockB(vector<string>* grid_ptr) {
    auto& grid = *grid_ptr;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != 'B')
                continue;
            for (auto& d : ds) {
                int ui = i + d.first;
                int uj = j + d.second;
                if (ui < 0 || n <= ui || uj < 0 || m <= uj)
                    continue;
                if (grid[ui][uj] == 'G')
                    return false;
                if (grid[ui][uj] == '.')
                    grid[ui][uj] = '#';
            }
        }
    }
    return true;
}


void Solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid)
        cin >> row;

    if (!CanBlockB(&grid)) {
        cout << "No" << endl;
        return;
    }

    bfs(&grid);

    int remain_cnt = 0;
    for (auto& row : grid)
        remain_cnt += count(row.begin(), row.end(), 'G');
    if (remain_cnt == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
