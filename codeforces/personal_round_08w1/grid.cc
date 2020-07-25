#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> grid(n, vector<int>(n));

    int i = 0;
    int j = 0;
    int j_start = 0;
    for (int x = 0; x < k; ++x) {
        grid[i][j%n] = 1;
        ++i;
        ++j;
        if (i >= n) {
            i = 0;
            ++j_start;
            j = j_start;
        }
    }

    if (k % n)
        cout << 2 << endl;
    else
        cout << 0 << endl;

    for (auto& row : grid) {
        for (auto& c : row)
            cout << c;
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
