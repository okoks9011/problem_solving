#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.rbegin(), a.rend());
    if (a[0] >= a[1]+a[2]) {
        cout << "NO" << endl;
        return 0;
    }

    deque<int> result;
    for (int i = 0; i < n; ++i) {
        if (i % 2)
            result.emplace_back(a[i]);
        else
            result.emplace_front(a[i]);
    }
    cout << "YES" << endl;
    for (auto& ri : result)
        cout << ri << " ";
    cout << endl;
}
