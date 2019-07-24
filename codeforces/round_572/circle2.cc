#include <iostream>
#include <vector>
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

    swap(a[0], a[1]);
    cout << "YES" << endl;
    for (auto& ai : a)
        cout << ai << " ";
    cout << endl;
}
