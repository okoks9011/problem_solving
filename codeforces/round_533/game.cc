#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

void MakeMove(vector<string>* blocks_ptr, int i, int y, int x, int step) {
    auto& blocks = *blocks_ptr;
    if (y < 0 || blocks.size() <= y)
        return;
    if (x < 0 || blocks[y].size() <= x)
        return;
    if (blocks[y][x] != '.')
        return;

    blocks[y][x] = i+'0';
    if (step <= 1)
        return;

    vector<pair<int, int>> moves{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (auto& p : moves) {
        MakeMove(blocks_ptr, i, y+p.first, x+p.second, step-1);
    }
}

int Expand(vector<string>* blocks_ptr, int i, int si) {
    auto& blocks = *blocks_ptr;
    cout << "si: " << si << endl;

    for (int yi = 0; yi < blocks.size(); ++yi) {
        for (int xi = 0; xi < blocks[yi].size(); ++xi) {
            if (blocks[yi][xi] == i+'0') {
                MakeMove(blocks_ptr, i, yi-1, xi, si);
                MakeMove(blocks_ptr, i, yi, xi+1, si);
                MakeMove(blocks_ptr, i, yi+1, xi, si);
                MakeMove(blocks_ptr, i, yi, xi-1, si);
            }
        }
    }

    int cnt = 0;
    for (auto& row : blocks)
        cnt += count(row.begin(), row.end(), i+'0');
    return cnt;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> s(p+1);
    for (int i = 1; i <= p; ++i)
        cin >> s[i];

    vector<string> blocks(n);
    for (int i = 0; i < n; ++i)
        cin >> blocks[i];

    vector<int> cnt(p+1);
    for (int i = 1; i <= p; ++i) {
        for (auto& row : blocks)
            cnt[i] += count(row.begin(), row.end(), i+'0');
    }

    bool changed = false;
    do {
        changed = false;
        for (int i = 1; i <= p; ++i) {
            int new_cnt = Expand(&blocks, i, s[i]);
            cout << "cnt[" << i << "]: " << cnt[i] << " new_cnt: " << new_cnt << endl;
            if (cnt[i] != new_cnt) {
                cnt[i] = new_cnt;
                changed = true;
            }
        }

        for (auto& row : blocks) {
            cout << row << endl;
        }
    } while(changed);

    for (int i = 1; i <= p; ++i) {
        int cnt = 0;
        for (auto& row : blocks)
            cnt += count(row.begin(), row.end(), i+'0');
        cout << cnt << " ";
    }
    cout << endl;
}
