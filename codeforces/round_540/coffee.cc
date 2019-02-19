#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool PossibleToComplete(int m, int k, vector<int>& a) {
    long long acc = 0;
    int order = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j < i+k && j < a.size(); ++j) {
            int add = max(0, a[j] - order);
            acc += add;
        }
        i += k-1;
        ++order;
    }
    return acc >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int left = 1;
    int right = n;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (PossibleToComplete(m, mid, a)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << result << endl;
}
