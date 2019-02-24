#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <limits>

using namespace std;


void dfs(const vector<string>& grid, const pair<int, int>& p, set<pair<int, int>>* history_ptr) {
    int n = grid.size();
    if (p.first < 0 || n <= p.first || p.second < 0 || n <= p.second)
        return;
    if (grid[p.first][p.second] != '0')
        return;

    auto& history = *history_ptr;
    if (history.find(p) != history.end())
        return;

    history.emplace(p);
    vector<pair<int, int>> d{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto& di : d)
        dfs(grid, {p.first+di.first, p.second+di.second}, history_ptr);
}

set<pair<int, int>> FindComponent(const vector<string>& grid, const pair<int, int>& start) {
    set<pair<int, int>> result;
    dfs(grid, start, &result);
    return result;
}

int main() {
    int n;
    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1;
    --c1;
    --r2;
    --c2;

    vector<string> grid(n);
    for (auto& s : grid)
        cin >> s;

    auto start_comp = FindComponent(grid, {r1, c1});
    if (start_comp.find({r2, c2}) != start_comp.end()) {
        cout << "0" << endl;
        return 0;
    }

    auto end_comp = FindComponent(grid, {r2, c2});

    int result = numeric_limits<int>::max();
    for (auto& p1 : start_comp) {
        for (auto& p2 : end_comp) {
            int r_diff = p1.first - p2.first;
            int c_diff = p1.second - p2.second;
            result = min(result, r_diff*r_diff + c_diff*c_diff);
        }
    }
    cout << result << endl;
}
