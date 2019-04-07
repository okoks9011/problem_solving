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

pair<bool, vector<int>> Validate(int guess, const vector<int>& crypt) {
    vector<int> result(crypt.size()+1);
    result[0] = guess;
    for (int i = 1; i < result.size(); ++i) {
        if (crypt[i-1] % result[i-1])
            return {false, {}};

        result[i] = crypt[i-1] / result[i-1];
    }
    return {true, result};
}

void Solve() {
    int n, l;
    cin >> n >> l;

    vector<int> crypt(l);
    for (auto& c : crypt)
        cin >> c;

    auto m = Factorize(crypt[0]);
    auto val_result = Validate(m.first, crypt);
    if (!val_result.first)
        val_result = Validate(m.second, crypt);
    assert(val_result.first);
    auto& f = val_result.second;

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
