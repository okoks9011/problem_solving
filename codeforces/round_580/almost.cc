#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> a(2*n);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            a[i] = 2*i + 1;
            a[i+n] = 2*i + 2;
        } else {
            a[i+n] = 2*i + 1;
            a[i] = 2*i + 2;
        }
    }
    cout << "YES" << endl;
    for (auto& ai : a)
        cout << ai << " ";
    cout << endl;
}
