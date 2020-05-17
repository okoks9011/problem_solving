#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <cassert>


using namespace std;


struct Elem {
    int n = 0;
    int i = 0;
    int j = 0;

    Elem(int new_n, int new_i, int new_j) : n(new_n), i(new_i), j(new_j) {}
};


bool operator>(const Elem& lhs, const Elem& rhs) {
        return lhs.n > rhs.n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (auto& row : grid)
        cin >> row;
    vector<pair<int, int>> ds{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    vector<vector<int>> cnt(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto& d : ds) {
                int ni = i + d.first;
                int nj = j + d.second;
                if (ni < 0 || n <= ni || nj < 0 || m <= nj)
                    continue;
                if (grid[ni][nj] == '.')
                    ++cnt[i][j];
            }
        }
    }

    priority_queue<Elem, vector<Elem>, greater<Elem>> min_pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.')
                min_pq.emplace(cnt[i][j], i, j);
        }
    }

    int x_cnt = 0;
    while (x_cnt < k) {
        assert(!min_pq.empty());
        auto e = min_pq.top();
        min_pq.pop();
        if (cnt[e.i][e.j] < e.n)
            continue;

        grid[e.i][e.j] = 'X';

        for (auto& d : ds) {
            int ni = e.i + d.first;
            int nj = e.j + d.second;
            if (ni < 0 || n <= ni || nj < 0 || m <= nj)
                continue;
            if (grid[ni][nj] == '.') {
                --cnt[ni][nj];
                min_pq.emplace(cnt[ni][nj], ni, nj);
            }
        }
        ++x_cnt;
    }

    for (auto& row : grid)
        cout << row << endl;
}
