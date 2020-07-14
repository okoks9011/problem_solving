#include <iostream>
#include <vector>
#include <set>
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

    set<int> must;
    for (int i = 0; i <= n; ++i)
        must.emplace(i);
    must.erase(a.back());
    for (int i = n-1; i >= 0; --i) {
        if (b[i] == -1)
            b[i] = *must.rbegin();
        must.erase(b[i]);
    }

    for (auto& bi : b)
        cout << bi << " ";
    cout << endl;
}
