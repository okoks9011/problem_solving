#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define ll long long


using namespace std;


const int kMod = 1000000007;


void dfs(int cur, const vector<vector<int>>& adjs,
         vector<int>* ids_ptr, vector<int>* lows_ptr, vector<int>* stack_ptr, int* cnt_ptr,
         vector<char>* in_stack_ptr) {
    auto& ids = *ids_ptr;
    auto& lows = *lows_ptr;
    auto& in_stack = *in_stack_ptr;

    if (ids[cur] != -1)
        return;

    int cur_id = (*cnt_ptr)++;
    ids[cur] = cur_id;
    lows[cur] = cur_id;
    stack_ptr->emplace_back(cur_id);
    in_stack[cur_id];

    for (auto& adj : adjs[cur]) {
        dfs(adj, adjs, ids_ptr, lows_ptr, stack_ptr, cnt_ptr, in_stack_ptr);
        if (in_stack[adj])
            lows[cur] = min(lows[cur], lows[adj]);
    }

    if (ids[cur] == lows[cur]) {
        while (stack_ptr->size() > 0) {
            int e = stack_ptr->back();
            stack_ptr->pop_back();
            lows[e] = lows[cur];
            if (e == cur)
                break;
        }
    }
}


vector<int> Tarjan(const vector<vector<int>>& adjs) {
    int n = adjs.size();
    int cnt = 0;

    vector<int> ids(n, -1);
    vector<int> lows(n, -1);
    vector<int> stack;
    vector<char> in_stack(n);

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1)
            dfs(i, adjs, &ids, &lows, &stack, &cnt, &in_stack);
    }
    return lows;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    int m;
    cin >> m;

    vector<vector<int>> adjs(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjs[u].emplace_back(v);
    }

    vector<int> lows = Tarjan(adjs);
    unordered_map<int, vector<int>> prices;
    for (int i = 0; i < n; i++)
        prices[lows[i]].emplace_back(c[i]);

    ll min_price = 0LL;
    int min_num = 1;
    for (auto& p : prices) {
        auto& group = p.second;
        auto it = min_element(group.begin(), group.end());
        min_price += *it;
        min_num *= count(group.begin(), group.end(), *it);
        min_num %= kMod;
    }
    cout << min_price << " " << min_num << endl;
}
