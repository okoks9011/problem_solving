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

    for (int i = 0; i < n; ++i) {
        int a_odd = count(a[i].begin(), a[i].end(), 1) % 2;
        int b_odd = count(b[i].begin(), b[i].end(), 1) % 2;

        if (a_odd != b_odd) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int j = 0; j < m; ++j) {
        int a_odd = 0;
        for (int i = 0; i < n; ++i)
            a_odd += a[i][j];
        a_odd %= 2;

        int b_odd = 0;
        for (int i = 0; i < n; ++i)
            b_odd += b[i][j];
        b_odd %= 2;

        if (a_odd != b_odd) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
