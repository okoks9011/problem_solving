#include <iostream>
#include <vector>
#include <cassert>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    for (int i = 0; i < n; ++i) {
        if (i + 1 < a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> b(n, -1);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > cur) {
            b[i] = cur;
            cur = a[i];
        }
    }

    vector<char> used(n+1, false);
    int ui = n;
    used[a.back()] = true;
    for (int i = n-1; i >= 0; --i) {
        if (b[i] == -1) {
            while (used[ui] && ui > 0)
                --ui;
            b[i] = ui;
        }
        used[b[i]] = true;
    }

    for (auto& bi : b)
        cout << bi << " ";
    cout << endl;
}
