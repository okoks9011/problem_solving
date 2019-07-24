#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

void Solve() {
    int n, r, c, sr, sc;
    cin >> n >> r >> c >>sr >> sc;

    string inst;
    cin >> inst;

    unordered_map<char, pair<int ,int>> ds{
        {'N', {-1, 0}},
        {'E', {0, 1}},
        {'S', {1, 0}},
        {'W', {0, -1}}
    };

    set<pair<int, int>> visited;
    int cur_r = sr;
    int cur_c = sc;
    visited.emplace(cur_r, cur_c);
    for (auto& d : inst) {
        auto& cur_d = ds[d];
        while (visited.find({cur_r, cur_c}) != visited.end()) {
            cur_r += cur_d.first;
            cur_c += cur_d.second;
        }
        visited.emplace(cur_r, cur_c);
    }
    cout << cur_r << " " << cur_c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
