#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    int right_dist = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] != c.back()) {
            right_dist = (n-1) - i;
            break;
        }
    }

    int left_dist = 0;
    for (int i = n-1; i >= 0; --i) {
        if (c[i] != c.front()) {
            left_dist = i;
            break;
        }
    }
    cout << max(right_dist, left_dist) << endl;
}
