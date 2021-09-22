#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>


using namespace std;


const int kAlpha = 20;


void dfs(int cur, vector<char>* visited_ptr, const vector<unordered_set<int>> adjs) {
    auto& visited = *visited_ptr;
    if (visited[cur])
        return;

    visited[cur] = true;
    for (auto& adj : adjs[cur])
        dfs(adj, visited_ptr, adjs);
}


void Solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<unordered_set<int>> adjs(kAlpha);
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            cout << -1 << endl;
            return;
        }
        if (a[i] == b[i])
            continue;
        int u = a[i]-'a';
        int w = b[i]-'a';
        adjs[u].emplace(w);
        adjs[w].emplace(u);
    }

    int cnt = 0;
    vector<char> visited(kAlpha);
    for (int i = 0; i < kAlpha; i++) {
        if (!visited[i]) {
            ++cnt;
            dfs(i, &visited, adjs);
        }
    }
    cout << kAlpha-cnt << endl;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
