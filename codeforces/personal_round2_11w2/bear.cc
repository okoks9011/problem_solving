#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

void dfs(int cur, int cnt, const vector<unordered_set<int>>& adjs, vector<int>* comp_ptr) {
    auto& comp = *comp_ptr;
    comp[cur] = cnt;
    for (auto& adj : adjs[cur]) {
        if (comp[adj] != -1)
            continue;
        dfs(adj, cnt, adjs, comp_ptr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> adjs(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u].emplace(v);
        adjs[v].emplace(u);
    }

    vector<int> comp(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1)
            dfs(i, cnt, adjs, &comp);
        cnt++;
    }

    vector<vector<int>> groups(cnt);
    for (int i = 0; i < n; i++) {
        groups[comp[i]].emplace_back(i);
    }

    for (int i = 0; i < cnt; i++) {
        auto& group = groups[i];
        if (group.size() == 1)
            continue;

        for (int j = 0; j < group.size(); j++) {
            auto& gj = group[j];
            for (int k = j+1; k < group.size(); k++) {
                auto it = adjs[gj].find(group[k]);
                if (it == adjs[gj].end()) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
}
