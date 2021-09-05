#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(2*n);
    for (auto& ai : a)
        cin >> ai;
    sort(a.rbegin(), a.rend());

    for (int i = 1; i < 2*n; i++) {
        int x = a[0] + a[i];
        multiset<int> target(a.begin(), a.end());
        vector<pair<int, int>> history;

        while (target.size() > 0) {
            auto max_it = target.end();
            max_it--;
            int max_v = *max_it;
            target.erase(max_it);

            auto it = target.find(x - max_v);
            if (it == target.end())
                break;

            x = max_v;
            history.emplace_back(*it, max_v);
            target.erase(it);
        }

        if (target.size() == 0) {
            cout << "YES" << endl;
            cout << a[0] + a[i] << endl;
            for (auto& p : history)
                cout << p.first << " " << p.second << endl;
            return;
        }
    }

    cout << "NO" << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
