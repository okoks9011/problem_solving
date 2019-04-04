#include <iostream>
#include <vector>
#include <map>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i] >> q[i];

    long long result = 0;
    map<int, int> cur;
    for (int i = 0; i < n; ++i) {
        auto it = cur.upper_bound(p[i]);
        if (it != cur.end() && q[i] < it->second) {
            result += cur.size();
            continue;
        }

        it = cur.emplace(p[i], q[i]).first;
        while (it != cur.begin()) {
            auto t_it = it;
            --t_it;
            if (t_it->second < q[i])
                cur.erase(t_it);
            else
                break;
        }
        result += cur.size();
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
