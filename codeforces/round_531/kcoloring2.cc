#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;

        a.emplace_back(ai, i);
    }
    sort(a.begin(), a.end());

    vector<int> result(n);
    vector<vector<int>> colors(k);
    for (int i = 0; i < n; ++i) {
        colors[i%k].emplace_back(a[i].first);
        result[a[i].second] = i%k;
    }

    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < static_cast<int>(colors[j].size())-1; ++i) {
            if (colors[j][i] == colors[j][i+1]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (auto& r : result)
        cout << r+1 << " ";
    cout << endl;
}
