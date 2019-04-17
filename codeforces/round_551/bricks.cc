#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> a(m);
    for (auto& ai : a)
        cin >> ai;

    vector<int> b(n);
    for (auto& bi : b)
        cin >> bi;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto& row : grid) {
        for (auto& cell : row)
            cin >> cell;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j])
                cout << min(a[j], b[i]) << " ";
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}
