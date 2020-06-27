#include <iostream>
#include <vector>
#include <map>  // use tree map over hash map due to vicious input
#include <algorithm>

#define ll long long


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    map<ll, int> loc;
    int start = -1;
    ll acc = 0LL;
    loc[acc] = start;
    ll result = 0LL;
    for (int i = 0; i < n; ++i) {
        acc += a[i];
        auto it = loc.find(acc);
        if (it == loc.end()) {
            loc[acc] = i;
        } else {
            start = max(start, it->second + 1);
            it->second = i;
        }
        result += (i - start);
    }

    cout << result << endl;
}
