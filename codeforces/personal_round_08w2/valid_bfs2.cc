#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adjs(n+1);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        adjs[x].emplace_back(y);
        adjs[y].emplace_back(x);
    }

    vector<int> seq(n);
    vector<int> order(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
        order[seq[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        sort(adjs[i].begin(), adjs[i].end(),
             [&order](int v1, int v2){ return order[v1] < order[v2]; });
    }

    vector<int> q;
    vector<char> visited(n+1);
    q.emplace_back(1);
    visited[1] = true;

    vector<int> trail;
    while (!q.empty()) {
        vector<int> next_q;
        for (auto& cur : q) {
            trail.emplace_back(cur);
            for (auto& u : adjs[cur]) {
                if (visited[u])
                    continue;
                visited[u] = true;
                next_q.emplace_back(u);
            }
        }
        q = next_q;
    }

    if (trail == seq)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
