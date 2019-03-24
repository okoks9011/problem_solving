#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;

void PrintDelivery(const vector<vector<int>>& delivery) {
    for (auto& row : delivery) {
        for (auto& cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

void bfs(deque<pair<int, int>> q, vector<vector<int>>* delivery_ptr) {
    auto& delivery = *delivery_ptr;
    int r = delivery.size();
    int c = delivery[0].size();

    vector<pair<int, int>> ds{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();
        for (auto& d : ds) {
            int new_i = p.first + d.first;
            int new_j = p.second + d.second;
            if (new_i < 0 || r <= new_i || new_j < 0 || c <= new_j)
                continue;
            int new_t = delivery[p.first][p.second]+1;
            if (delivery[new_i][new_j] <= new_t)
                continue;
            delivery[new_i][new_j] = new_t;
            q.emplace_back(new_i, new_j);
        }
    }
}

int FindMaxDelivery(const vector<vector<int>>& delivery) {
    int result = 0;
    for (auto& row : delivery)
        result = max(result, *max_element(row.begin(), row.end()));
    return result;
}

int Solve() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> delivery(r, vector<int>(c, r+c));
    deque<pair<int, int>> q;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char tmp;
            cin >> tmp;
            if (tmp != '0') {
                q.emplace_back(i, j);
                delivery[i][j] = 0;
            }
        }
    }
    bfs(q, &delivery);

    int result = r + c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            vector<vector<int>> tmp_delivery(delivery);
            tmp_delivery[i][j] = 0;
            bfs({{i, j}}, &tmp_delivery);
            result = min(result, FindMaxDelivery(tmp_delivery));
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
