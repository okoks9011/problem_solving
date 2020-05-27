#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;


int dfs(int node, int parent, int depth, vector<int>* happy_ptr,
        const vector<vector<int>>& adjs) {
    int size = 1;
    for (auto& u : adjs[node]) {
        if (u != parent)
            size += dfs(u, node, depth+1, happy_ptr, adjs);
    }
    auto& happy = *happy_ptr;
    happy[node] = depth - size;

    return size;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adjs(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adjs[u].emplace_back(v);
        adjs[v].emplace_back(u);
    }

    vector<int> happy(n);
    dfs(0, -1, 1, &happy, adjs);
    nth_element(happy.begin(), happy.begin()+k, happy.end(), greater<>());
    cout << accumulate(happy.begin(), happy.begin()+k, 0LL) << endl;
}
