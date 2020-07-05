#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    if (k % n)
        ans = 2;

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
            j = ++j_start;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << grid[i][j];
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
