#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<pair<int, int>> seg(m);
    for (auto& si : seg) {
        cin >> si.first >> si.second;
        --si.first;
        --si.second;
    }

    int result = 0;
    vector<int> best_choose;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp(a);
        vector<int> choose;
        for (int j = 0; j < m; ++j) {
            if (seg[j].first <= i && i <= seg[j].second)
                continue;

            choose.emplace_back(j);
            for (int k = seg[j].first; k <= seg[j].second; ++k)
                --tmp[k];
        }

        int diff = tmp[i] - *min_element(tmp.begin(), tmp.end());
        if (diff > result) {
            result = diff;
            best_choose = choose;
        }
    }

    cout << result << endl;
    cout << best_choose.size() << endl;
    for (auto& c : best_choose)
        cout << c+1 << " ";
    cout << endl;
}
