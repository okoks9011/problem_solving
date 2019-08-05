#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    for (int i = 0; i < n; ++i) {
        int lower = max(0, i-x);
        int left_min = *min_element(a.begin()+lower, a.begin()+i);
        if (x != 0 && i != 0 && a[i] >= left_min)
            continue;

        int upper = min(n-1, i+y);
        int right_min = *min_element(a.begin()+(i+1), a.begin()+(upper+1));
        if (y != 0 && i != n-1 && a[i] >= right_min)
            continue;

        cout << i+1 << endl;
        return 0;
    }
    assert(false);
}
