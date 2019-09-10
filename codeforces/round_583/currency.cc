#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, d, e;
    cin >> n >> d >> e;

    int x = max(d, 5*e);
    int y = min(d, 5*e);

    int result = numeric_limits<int>::max();
    for (int cur = 0; cur <= n; cur += x) {
        int remain = n - cur;
        result = min(result, remain % y);
    }
    cout << result << endl;
}
