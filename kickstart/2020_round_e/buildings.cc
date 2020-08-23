#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int necessary = a + b - c;
    if (necessary > n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int margin = n - necessary;
    int a_only = a - c;
    int b_only = b - c;
    if (margin && a_only == 0 && b_only == 0 && c == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int left_hide = 0;
    int mid_hide = 0;
    int right_hide = 0;
    if (a_only)
        left_hide = margin;
    else if (b_only)
        right_hide = margin;
    else if (c > 1)
        mid_hide = margin;

    vector<int> result;
    for (int i = 0; i < a_only; ++i)
        result.emplace_back(n-1);
    for (int i = 0; i < left_hide; ++i)
        result.emplace_back(n-2);

    result.emplace_back(n);
    for (int i = 0; i < mid_hide; ++i)
        result.emplace_back(n-2);
    for (int i = 1; i < c; ++i)
        result.emplace_back(n);

    for (int i = 0; i < right_hide; ++i)
        result.emplace_back(n-2);
    for (int i = 0; i < b_only; ++i)
        result.emplace_back(n-1);

    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
    }
}
