#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjs(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u].emplace_back(v);
        adjs[v].emplace_back(u);
    }

    vector<int> comp(n, -1);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (adjs[i].size() == 0) {
            comp[i] = -2;
            continue;
        }

        comp[i] = flag;
        vector<int> cur{i};
        flag = flag == 0 ? 1 : 0;
        while (cur.size() > 0) {
            vector<int> next;
            for (auto& elem : cur) {
                for (auto& adj : adjs[elem]) {
                    if (comp[adj] == comp[elem]) {
                        cout << -1 << endl;
                        return 0;
                    }
                    if (comp[adj] != -1) {
                        continue;
                    }
                    comp[adj] = flag;
                    next.emplace_back(adj);
                }
            }
            cur = next;
            flag = flag == 0 ? 1 : 0;
        }
    }

    for (auto& ci : comp)
        cout << ci << endl;

    cout << count(comp.begin(), comp.end(), 1) << endl;
    for (int i = 0; i < n; i++) {
        if (comp[i] == 1)
            cout << i-1 << " ";
    }
    cout << endl;
    cout << count(comp.begin(), comp.end(), 2) << endl;
    for (int i = 0; i < n; i++) {
        if (comp[i] == 2)
            cout << i-1 << " ";
    }
    cout << endl;
}
