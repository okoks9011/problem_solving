#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (auto& ai : a) {
        for (auto& aij : ai)
            cin >> aij;
    }

    vector<vector<int>> b(n, vector<int>(m));
    for (auto& bi : b) {
        for (auto& bij : bi)
            cin >> bij;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                a[0][0] ^= 1;
                a[i][0] ^= 1;
                a[0][j] ^= 1;
                a[i][j] ^= 1;
            }
        }
    }

    if (a == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
