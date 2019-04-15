#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void Solve() {
    int n, b, f;
    cin >> n >> b >> f;

    vector<int> w(n-b);
    for (int i = f-1; i >= 0; --i) {
        int mask = 1 << i;
        string q;
        for (int j = 0; j < n; ++j) {
            if (mask & j)
                q += '1';
            else
                q += '0';
        }
        cout << q << endl;

        string ans;
        cin >> ans;
        assert(ans.size() == w.size());
        for (int j = 0; j < w.size(); ++j) {
            w[j] = w[j] << 1;
            if (ans[j] == '1')
                w[j] += 1;
        }
    }
    vector<int> total(n);
    int chunk = 0;
    for (int i = 0; i < w.size(); ++i) {
        if (i > 0 && w[i-1] > w[i])
            ++chunk;
        total[32*chunk+w[i]] = 1;
    }
    for (int i = 0; i < total.size(); ++i) {
        if (!total[i])
            cout << i << " ";
    }
    cout << endl;

    string correct;
    cin >> correct;
    if (correct != "1")
        exit(0);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
