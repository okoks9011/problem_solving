#include <iostream>
#include <unordered_set>

using namespace std;


bool IsDistinct(int x) {
    unordered_set<int> ds;
    while (x) {
        int cur = x % 10;
        auto it = ds.find(cur);
        if (it != ds.end())
            return false;

        ds.emplace(cur);
        x /= 10;
    }
    return true;
}


int main() {
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; ++i) {
        if (!IsDistinct(i))
            continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
}
