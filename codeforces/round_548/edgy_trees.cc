#include <iostream>
#include <vector>

using namespace std;

const int kDiv = 1000000007;

int DivPow(int c, int k) {
    long long result = 1;
    for (int i = 0; i < k; ++i) {
        result *= c;
        result %= kDiv;
    }

    return static_cast<int>(result);
}

int FindComp(const vector<vector<int>>& g, int i, int cur, vector<int>* comp_ptr) {
    auto& comp = *comp_ptr;
    comp[i] = cur;

    int result = 1;
    for (auto& j : g[i]) {
        if (!comp[j])
            result += FindComp(g, j, cur, comp_ptr);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c)
            continue;

        --u;
        --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> comp(n);
    int cur = 1;
    vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        if (!comp[i]) {
            cnt.emplace_back(FindComp(g, i, cur, &comp));
            ++cur;
        }
    }

    int result = DivPow(n, k);
    for (auto& c : cnt) {
        result += kDiv;
        result -= DivPow(c, k);
        result %= kDiv;
    }
    cout << result << endl;
}
