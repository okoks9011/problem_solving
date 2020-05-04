#include <vector>
#include <iostream>
#include <set>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for (auto& row : m) {
        for (auto& c : row)
            cin >> c;
    }

    int dig_sum = 0;
    for (int i = 0; i < n; ++i)
        dig_sum += m[i][i];

    int repeat_row = 0;
    for (auto& row : m) {
        vector<char> visited(n+1);
        for (auto& c : row) {
            if (visited[c]) {
                ++repeat_row;
                break;
            }
            visited[c] = true;
        }
    }

    int repeat_col = 0;
    for (int j = 0; j < n; ++j) {
        vector<char> visited(n+1);
        for (int i = 0; i < n; ++i) {
            auto& c = m[i][j];
            if (visited[c]) {
                ++repeat_col;
                break;
            }
            visited[c] = true;
        }
    }

    cout << dig_sum << " " << repeat_row << " " << repeat_col;
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
