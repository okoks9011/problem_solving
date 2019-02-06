#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cctype>

using namespace std;

struct Elem {
    int r = 0;
    int c = 0;
    int s = 0;
    Elem() = default;
    Elem(int row, int column, int step) : r(row), c(column), s(step) {}
};

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> s(p+1);
    for (int i = 1; i <= p; ++i)
        cin >> s[i];

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<deque<Elem>> cur_q(p+1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isdigit(grid[i][j]))
                cur_q[grid[i][j]-'0'].emplace_back(i, j, 0);
        }
    }

    vector<pair<int, int>> moves{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool cont = false;
    do {
        vector<deque<Elem>> next_q(p+1);
        for (int i = 1; i <= p; ++i) {
            while (!cur_q[i].empty()) {
                auto cur = cur_q[i].front();
                cur_q[i].pop_front();

                for (auto& move : moves) {
                    int r = cur.r + move.first;
                    int c = cur.c + move.second;
                    int step = cur.s + 1;

                    if (r < 0 || n <= r)
                        continue;
                    if (c < 0 || m <= c)
                        continue;
                    if (grid[r][c] != '.')
                        continue;
                    grid[r][c] = '0'+i;

                    if (step < s[i])
                        cur_q[i].emplace_back(r, c, step);
                    else
                        next_q[i].emplace_back(r, c, 0);
                }
            }
        }
        cur_q = next_q;
        cont = any_of(cur_q.begin(), cur_q.end(), [](deque<Elem>& q){ return !q.empty(); });
    } while(cont);

    for (int i = 1; i <= p; ++i) {
        int cnt = 0;
        for (auto& row : grid)
            cnt += count(row.begin(), row.end(), i+'0');
        cout << cnt << " ";
    }
    cout << endl;
}
