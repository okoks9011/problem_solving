#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

pair<int, int> Factorize(int x) {
    int sqrt_x = static_cast<int>(sqrt(x));
    for (int i = 2; i <= sqrt_x; ++i) {
        if (x % i == 0)
            return {i, x / i};
    }
    assert(false);
}

int Common(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first || p1.first == p2.second)
        return p1.first;
    if (p1.second == p2.first || p1.second == p2.second)
        return p1.second;
    assert(false);
}

void Solve() {
    int n, l;
    cin >> n >> l;

    vector<int> crypt(l);
    for (auto& c : crypt)
        cin >> c;

    vector<pair<int, int>> f(l);
    map<int, char> dic;
    for (int i = 0; i < l; ++i) {
        auto nums = Factorize(crypt[i]);
        dic.emplace(nums.first, 0);
        dic.emplace(nums.second, 0);
        f[i] = nums;
    }

    assert(dic.size() == 26);

    char cur = 'A';
    for (auto& p : dic) {
        p.second = cur;
        ++cur;
    }

    string result;
    result += dic[crypt[0]/Common(f[0], f[1])];
    for (int i = 1; i < l; ++i) {
        auto c = Common(f[i-1], f[i]);
        cout << f[i].first  << ", " << f[i].second << endl;
        cout << "common: " << c << " => " << dic[c] <<endl;
        result += dic[c];
    }
    result += dic[crypt[l-1]/Common(f[l-2], f[l-1])];

    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
