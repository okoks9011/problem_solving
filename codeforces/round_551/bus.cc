#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        int si, di;
        cin >> si >> di;
        arr[i] = si;
        if (arr[i] >= t)
            continue;

        int diff = t - si;
        arr[i] += ((diff+di-1)/di) * di;
    }
    cout << min_element(arr.begin(), arr.end()) - arr.begin() + 1 << endl;
}
