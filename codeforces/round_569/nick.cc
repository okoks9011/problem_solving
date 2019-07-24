#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        if (ai >= 0)
            ai = -ai - 1;
    }

    if (n % 2 == 1) {
        auto it = min_element(a.begin(), a.end());
        *it = -(*it) - 1;
    }

    for (auto& ai : a)
        cout << ai << " ";
    cout << endl;
}
