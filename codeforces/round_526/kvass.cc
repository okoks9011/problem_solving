#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::min_element;

long long LeaveJ(const vector<int>& v, int j) {
    long long total = 0;
    for (auto& vi : v) {
        if (vi > j)
            total += vi - j;
    }
    return total;
}

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int left = 0;
    int right = *min_element(v.begin(), v.end());
    int max_level = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long pour = LeaveJ(v, mid);
        if (pour >= s) {
            max_level = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << max_level << endl;
}
