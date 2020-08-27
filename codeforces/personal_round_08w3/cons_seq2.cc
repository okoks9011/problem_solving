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

    map<int, int> dp;
    for (int i = 0; i < n; ++i) {
        auto it = dp.find(a[i]-1);
        if (it != dp.end())
            dp[a[i]] = it->second + 1;
        else
            dp[a[i]] = 1;
    }

    int max_len = 0;
    int max_x = 0;
    for (auto& p : dp) {
        if (p.second > max_len) {
            max_len = p.second;
            max_x = p.first;
        }
    }
    assert(max_len != 0);

    int cur = max_x;
    vector<int> result;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == cur) {
            result.emplace_back(i);
            --cur;
        }
    }
    assert(result.size() == max_len);

    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto& ri : result)
        cout << ri+1 << " ";
    cout << endl;
}
