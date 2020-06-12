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
    for (auto& ai : a)
        cin >> ai;

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    vector<int> pref(n);
    pref[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            pref[i] = pref[i-1] + 1;
        else
            pref[i] = 1;
    }

    vector<int> suf(n);
    suf[n-1] = 1;
    for (int i = n-2; i >= 0; --i) {
        if (a[i] < a[i+1])
            suf[i] = suf[i+1] + 1;
        else
            suf[i] = 1;
    }

    int result = max(1 + suf[1], pref[n-2] + 1);
    for (int i = 1; i < n-1; ++i) {
        if (a[i+1] - a[i-1] > 1) {
            result = max(result, pref[i-1] + 1 + suf[i+1]);
        } else {
            result = max(result, pref[i-1] + 1);
            result = max(result, suf[i+1] + 1);
        }
    }
    cout << result << endl;
}
