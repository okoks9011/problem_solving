#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kMod = 1000000007;

enum Color {
    kEmpty = 0,
    kBlack,
    kWhite,
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<int> r(h);
    for (auto& ri : r)
        cin >> ri;

    vector<int> c(w);
    for (auto& ci : c)
        cin >> ci;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        int x;
        for (x = 0; x < r[i]; ++x)
            grid[i][x] = kBlack;
        if (x < w)
            grid[i][x] = kWhite;
    }

    for (int j = 0; j < w; ++j) {
        int y;
        for (y = 0; y < c[j]; ++y) {
            if (grid[y][j] == kWhite) {
                cout << "0" << endl;
                return 0;
            }
            grid[y][j] = kBlack;
        }
        if (y < h) {
            if (grid[y][j] == kBlack) {
                cout << "0" << endl;
                return 0;
            }
            grid[y][j] = kWhite;
        }
    }

    int empty_cnt = 0;
    for (auto& row : grid)
        empty_cnt += count(row.begin(), row.end(), kEmpty);

    int result = 1;
    for (int i = 0; i < empty_cnt; ++i) {
        result *= 2;
        result %= kMod;
    }
    cout << result << endl;
}
