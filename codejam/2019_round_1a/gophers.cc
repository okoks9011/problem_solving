#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <cassert>

using namespace std;

void Solve(int n, int m) {
    set<int> candi;
    for (int i = 1; i <= m; ++i)
        candi.emplace(i);

    for (int cur = 2; cur <= 18; ++cur) {
        for (int i = 0; i < 18; ++i)
            cout << cur << " ";
        cout << endl;
        vector<int> ret(18);
        for (auto& ri : ret)
            cin >> ri;
        int mod = accumulate(ret.begin(), ret.end(), 0) % cur;

        for (int i = 1; i <= m; ++i) {
            if (i % cur != mod)
                candi.erase(i);
        }
        if (candi.size() == 1) {
            cout << *candi.begin() << endl;
            int res;
            cin >> res;
            assert(res == 1);
            return;
        }
    }
}

int main() {
    int t, n, m;
    cin >> t >> n >> m;

    for (int i = 0; i < t; ++i)
        Solve(n, m);
}
