#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int result = numeric_limits<int>::max();
    for (int x = 1; x <= n; ++x) {
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            int e = abs(x-i) + abs(i-1) + abs(1-x);
            cur += 2 * e * a[i];
        }
        result = min(result, cur);
    }

    cout << result << endl;
}
