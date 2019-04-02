#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> c(n+1);
    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        cin >> c[i];
    }

    vector<int> evict(c);
    for (int i = 1; i <= n; ++i) {
        if (p[i] == -1)
            continue;

        evict[p[i]] = evict[p[i]] && c[i];
    }

    if (all_of(evict.begin()+1, evict.end(), [](int a){return a == 0;})) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (evict[i])
            cout << i << " ";
    }
    cout << endl;
}
