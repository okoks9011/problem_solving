#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> b(n);
    for (auto& bi : b)
        cin >> bi;

    vector<int> c(m);
    for (auto& ci : c)
        cin >> ci;

    auto it = find(b.begin(), b.end(), c.back());
    if (it == b.end()) {
        cout << "NO" << endl;
        return;
    }

    unordered_map<int, vector<int>> goals;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            goals[b[i]].emplace_back(i);
    }

    int last_idx = -1;
    auto git = goals.find(c.back());
    if (git == goals.end()) {
        last_idx = it - b.begin();
    } else {
        auto& t = git->second;
        last_idx = t.back();
        t.pop_back();
        if (t.size() == 0)
            goals.erase(git);
    }

    vector<int> assign(m);
    for (int i = 0; i < m-1; i++) {
        auto cit = goals.find(c[i]);
        if (cit == goals.end()) {
            assign[i] = last_idx;
        } else {
            auto& t = cit->second;
            assign[i] = t.back();
            t.pop_back();
            if (t.size() == 0)
                goals.erase(cit);
        }
    }
    assign[m-1] = last_idx;

    if (goals.size() > 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (auto& v : assign)
        cout << v+1 << " ";
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
