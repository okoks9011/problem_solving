#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> FindKeyFactor(const vector<int>& c) {
    for (int i = 1; i < c.size(); ++i) {
        if (c[i-1] != c[i])
            return {i, gcd(c[i-1], c[i])};
    }
    assert(false);
}

vector<int> ExtractFactors(int key, const vector<int>& t) {
    vector<int> result;
    int cur = key;
    for (auto& ti : t) {
        cur = ti / cur;
        result.emplace_back(cur);
    }
    return result;
}

void Solve() {
    int n, l;
    cin >> n >> l;

    vector<int> c(l);
    for (auto& ci : c)
        cin >> ci;

    auto p = FindKeyFactor(c);
    vector<int> left(c.begin(), c.begin()+p.first);
    auto left_factors = ExtractFactors(p.second, {left.rbegin(), left.rend()});
    reverse(left_factors.begin(), left_factors.end());
    auto right_factors = ExtractFactors(p.second, {c.begin()+p.first, c.end()});

    vector<int> f(left_factors);
    f.emplace_back(p.second);
    f.insert(f.end(), right_factors.begin(), right_factors.end());

    map<int, char> dic;
    for (auto& fi : f)
        dic.emplace(fi, 0);
    assert(dic.size() == 26);

    char cur = 'A';
    for (auto& p : dic) {
        p.second = cur;
        ++cur;
    }

    string result;
    for (int i = 0; i < f.size(); ++i)
        result += dic[f[i]];

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
