#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> h(2, vector<long long>(n+1));
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> h[i][j];
    }

    for (int i = 2; i <= n; ++i) {
        h[0][i] += max(h[1][i-2], h[1][i-1]);
        h[1][i] += max(h[0][i-2], h[0][i-1]);
    }
    cout << max(h[0][n], h[1][n]) << endl;
}
