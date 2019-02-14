#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> c(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dishes;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        dishes.push({c[i], i});
    }

    vector<pair<int, int>> customers(m);
    for (auto& p : customers) {
        cin >> p.first >> p.second;
        --p.first;
    }

    for (auto& p : customers) {
        long long cost = 0;
        while (p.second != 0) {
            if (dishes.empty()) {
                cost = 0;
                break;
            }
            int picked = p.first;
            if (a[picked] == 0)
                picked = dishes.top().second;

            int eat = min(a[picked], p.second);
            cost += 1LL * eat * c[picked];
            a[picked] -= eat;
            p.second -= eat;

            while (!dishes.empty() && a[dishes.top().second] == 0)
                dishes.pop();
        }
        cout << cost << endl;
    }
}
