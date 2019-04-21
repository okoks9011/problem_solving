#include <iostream>
#include <vector>

using namespace std;

bool CanBuildPalin(int li, int ri, const vector<vector<int>>& acc) {
    vector<int> target(acc[ri]);
    if (li > 0) {
        for (int i = 0; i < 26; ++i)
            target[i] -= acc[li-1][i];
    }

    int odd = 0;
    for (int i = 0; i < 26; ++i) {
        if (target[i] % 2)
            ++odd;
        if (odd > 1)
            return false;
    }
    return true;
}

int Solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> acc(n);
    vector<int> cur(26);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        ++cur[c-'A'];
        acc[i] = cur;
    }

    int result = 0;
    for (int i = 0; i < q; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        --ri;
        if (CanBuildPalin(li, ri, acc))
            ++result;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
