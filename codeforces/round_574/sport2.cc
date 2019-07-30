#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int left = 0;
    int right = n;
    int result = -1;
    int target = n + k;
    while (left <= right) {
        int mid = left + (right-left) / 2;
        long long v = ((1LL*mid*mid) + 3*mid) / 2;
        if (v < target) {
            left = mid + 1;
        } else if (v > target) {
            right = mid - 1;
        } else {
            result = mid;
            break;
        }
    }
    assert(result != -1);

    cout << n - result << endl;
}
