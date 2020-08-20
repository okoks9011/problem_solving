#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> dp_len(n, 1);
    vector<int> dp_prev(n, -1);
    map<int, int> loc;

    for (int i = 0; i < n; ++i) {
        auto it = loc.find(a[i]-1);
        if (it != loc.end()) {
            int prev = it->second;
            dp_prev[i] = prev;
            dp_len[i] = dp_len[prev] + 1;
        }
        loc[a[i]] = i;
    }

    int max_i = -1;
    int max_v = 0;
    for (int i = 0; i < n; ++i) {
        if (dp_len[i] > max_v) {
            max_v = dp_len[i];
            max_i = i;
        }
    }
    assert(max_i != -1);

    vector<int> result;
    int cur = max_i;
    while (cur != -1) {
        result.emplace_back(cur);
        cur = dp_prev[cur];
    }
    reverse(result.begin(), result.end());

    cout << max_v << endl;
    for (auto& ri : result)
        cout << ri + 1 << " ";
    cout << endl;
}
