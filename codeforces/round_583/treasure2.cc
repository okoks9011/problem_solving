#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid)
        cin >> row;

    vector<vector<char>> visited(n, vector<char>(m));
    visited[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#')
                continue;
            if (1 <= i && visited[i-1][j] == 1)
                visited[i][j] = 1;
            if (1 <= j && visited[i][j-1] == 1)
                visited[i][j] = 1;
        }
    }
    if (visited[n-1][m-1] != 1) {
        cout << "0" << endl;
        return 0;
    }

    visited[n-1][m-1] = 2;
    for (int i = n-1; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {
            if (grid[i][j] == '#' || visited[i][j] != 1)
                continue;
            if (i < n-1 && visited[i+1][j] == 2)
                visited[i][j] = 2;
            if (j < m-1 && visited[i][j+1] == 2)
                visited[i][j] = 2;
        }
    }

    for (int s = 1; s < n+m-2; ++s) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int j = s - i;
            if (0 <= j && j < m && visited[i][j] == 2)
                ++sum;
        }
        if (sum == 1) {
            cout << "1" << endl;
            return 0;
        }
    }
    cout << "2" << endl;
}
