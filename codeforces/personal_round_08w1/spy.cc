#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cassert>


using namespace std;


vector<string> GenCandi(const string& a1, const string& a2) {
    assert(a1.size() == a2.size());
    int m = a1.size();
    vector<int> diff;
    for (int i = 0; i < m; ++i) {
        if (a1[i] != a2[i])
            diff.emplace_back(i);
    }

    vector<string> result;
    if (diff.empty()) {
        for (int i = 0; i < m; ++i) {
            string tmp(a1);
            for (int c = 'a'; c <= 'z'; ++c) {
                tmp[i] = c;
                result.emplace_back(tmp);
            }
        }
    } else if (diff.size() == 1) {
        string tmp(a1);
        int di = diff[0];
        for (int c = 'a'; c <= 'z'; ++c) {
            tmp[di] = c;
            result.emplace_back(tmp);
        }
    } else if (diff.size() == 2) {
        int di = diff[0];
        string tmp1(a1);
        tmp1[di] = a2[di];
        result.emplace_back(tmp1);

        string tmp2(a2);
        tmp2[di] = a1[di];
        result.emplace_back(tmp2);
    } else {
        return {};
    }
    return result;
}


void Solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_set<string> candi;
    vector<string> init = GenCandi(a[0], a[0]);
    for (auto& ci : init)
        candi.emplace(ci);

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            unordered_set<string> next_candi;
            vector<string> cur = GenCandi(a[i], a[j]);
            for (auto& ci : cur) {
                auto it = candi.find(ci);
                if (it != candi.end())
                    next_candi.emplace(ci);
            }
            if (next_candi.empty()) {
                cout << -1 << endl;
                return;
            }
            candi = next_candi;
        }
    }
    cout << *candi.begin() << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
