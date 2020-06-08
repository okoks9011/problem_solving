#include <iostream>
#include <set>
#include <unordered_set>
#include <cassert>
#include <limits>


using namespace std;


long long SumTo(int a) {
    if (a <= 0)
        return 0;
    return 1LL * a * (a + 1) / 2;
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    set<int> ps;
    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        ps.emplace(pi);
    }

    long long result = 0;
    int cnt = 0;
    int last = numeric_limits<int>::max();
    unordered_set<int> selected;
    for (auto it = ps.rbegin(); it != ps.rend(); ++it) {
        if (cnt >= k)
            break;

        int cur = *it;
        if (cur >= last)
            continue;
        if (selected.find(cur) != selected.end())
            continue;

        int match = *it - m + 1;
        if (ps.find(match) == ps.end())
            continue;

        cout << "cur: " << cur << " match: " << match << endl;
        result += (SumTo(cur) - SumTo(match-1));
        last = match;
        selected.emplace(match);
        ++cnt;
    }
    assert(cnt == k);

    cout << result << endl;
}
