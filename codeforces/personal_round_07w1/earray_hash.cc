#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define ll long long


using namespace std;


struct MyHash {
    size_t operator()(const ll& v) const {
        return v ^ (v >> 16);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_map<ll, int, MyHash> loc;
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
