#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<unordered_set<int>> adjs(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u].emplace(v);
        adjs[v].emplace(u);
    }

    deque<int> trail(n);
    for (auto& ti : trail)
        cin >> ti;

    if (t[0] != 0) {
        cout << "No" << endl;
        return 0;
    }

    deque<int> q;
    vector<char> visited(n);
    q.emplace_back(0);
    visited[0] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();

        int child_cnt = adj[cur].size();
        if (cur != 0)
            --child_cnt;
    }
}
