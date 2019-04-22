#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

int FindGophers(const unordered_map<int, int>& resp) {
    for (int x = 1; x <= 1000000; ++x) {
        if (all_of(resp.begin(), resp.end(),
                   [&](const pair<int, int>& p){ return x % p.first == p.second; }))
            return x;
    }
    assert(false);
}

void Solve(int n, int m) {
    vector<int> q{16, 9, 5, 7, 11, 13, 17};
    unordered_map<int, int> resp;

    for (auto& qi : q) {
        for (int i = 0; i < 18; ++i)
            cout << qi << " ";
        cout << endl;

        vector<int> ret(18);
        for (auto& ri : ret)
            cin >> ri;

        resp[qi] = accumulate(ret.begin(), ret.end(), 0) % qi;
    }

    cout << FindGophers(resp) << endl;

    int verdict;
    cin >> verdict;
    assert(verdict == 1);
}

int main() {
    int t, n, m;
    cin >> t >> n >> m;

    for (int i = 0; i < t; ++i)
        Solve(n, m);
}
