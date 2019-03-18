#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void dfs(const vector<vector<int>>& grid, pair<int, int> cur, pair<int, int> end,
         int energy, vector<vector<int>>* max_energy_ptr) {
    int i = cur.first;
    int j = cur.second;
    if (i < 0 || grid.size() <= i || j < 0 || grid[i].size() <= j)
        return;
    if (grid[i][j] == -100000)
        return;

    int cur_energy = energy + grid[i][j];
    if (cur_energy < 0)
        return;

    auto& max_energy = *max_energy_ptr;
    if (cur_energy <= max_energy[i][j])
        return;

    max_energy[i][j] = cur_energy;
    vector<pair<int, int>> ds{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto& d : ds)
        dfs(grid, {i+d.first, j+d.second}, end, cur_energy, max_energy_ptr);
}

int Solve() {
    int n, m, e, sr, sc, tr, tc;
    cin >> n >> m >> e >> sr >> sc >> tr >> tc;
    --sc;
    --sr;
    --tr;
    --tc;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto& row : grid) {
        for (auto& v : row)
            cin >> v;
    }

    vector<vector<int>> max_energy(n, vector<int>(m, -1));
    dfs(grid, {sr, sc}, {tr, tc}, e, &max_energy);

    return max_energy[tr][tc];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
