#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> deg(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ++deg[u];
        ++deg[v];
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
