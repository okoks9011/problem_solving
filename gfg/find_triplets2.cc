#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    sort(a.begin(), a.end());
    int result = 0;
    for (int i = 0; i < n-2; ++i) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = a[left] + a[right] + a[i];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                ++result;
                ++left;
                --right;
            }
        }
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
