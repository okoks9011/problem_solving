#include <iostream>
#include <vector>
#include <cassert>


using namespace std;


int CountRestaurant(int cur, int parent, int cats,
                    const int m, const vector<int>& a, const vector<vector<int>>& adjs) {
    int n = a.size();
    assert(n > cur);

    if (a[cur])
        cats += 1;
    else
        cats = 0;
    if (cats > m)
        return 0;

    int result = 0;
    for (auto& adj : adjs[cur]) {
        if (adj == parent)
            continue;
        result += CountRestaurant(adj, cur, cats, m, a, adjs);
    }
    if (cur != 0 && adjs[cur].size() == 1)
        ++result;
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<vector<int>> adjs(n);
    for (int i = 0; i < n-1; ++i) {
        int u, w;
        cin >> u >> w;
        --u;
        --w;
        adjs[u].emplace_back(w);
        adjs[w].emplace_back(u);
    }

    cout << CountRestaurant(0, -1, 0, m, a, adjs) << endl;
}
