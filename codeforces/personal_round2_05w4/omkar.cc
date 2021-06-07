#include <iostream>
#include <vector>

#define ll long long


using namespace std;

ll Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int sorted_left = 0;
    for (int i = 0; i < n; ++i) {
        if (i+1 != a[i])
            break;
        ++sorted_left;
    }
    if (sorted_left == n)
        return 0;

    int sorted_right = n-1;
    for (int i = n-1; i >= 0; --i) {
        if (i+1 != a[i])
            break;
        --sorted_right;
    }

    for (int i = sorted_left; i <= sorted_right; ++i) {
        if (i+1 == a[i])
            return 2;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        cout << Solve() << endl;
}
