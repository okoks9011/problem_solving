#include <iostream>
#include <set>


using namespace std;


void Solve() {
    int n, m;
    cin >> n >> m;

    set<int> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.emplace(ai);
    }

    set<int> b;
    for (int i = 0; i < m; ++i) {
        int bi;
        cin >> bi;
        b.emplace(bi);
    }

    for (auto& ai : a) {
        auto it = b.find(ai);
        if (it == b.end())
            continue;
        cout << "YES" << endl;
        cout << 1 << " " << ai << endl;
        return;
    }
    cout << "NO" << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
