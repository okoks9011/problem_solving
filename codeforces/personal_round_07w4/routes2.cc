#include <iostream>
#include <vector>


using namespace std;


const int kInf = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjs(n, vector<int>(n, kInf));
    bool direct_rail = false;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u][v] = 1;
        adjs[v][u] = 1;
    }
    if (adjs[0][n-1] == 1 || adjs[n-1][0] == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                adjs[i][j] = adjs[i][j] == 1 ? kInf : 1;
        }
    }

    for (int i = 0; i < n; ++i)
        adjs[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                adjs[i][j] = min(adjs[i][j], adjs[i][k] + adjs[k][j]);
        }
    }
    if (adjs[0][n-1] >= kInf)
        cout << -1 << endl;
    else
        cout << adjs[0][n-1] << endl;
}
