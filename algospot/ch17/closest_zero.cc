#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& ai : a)
        cin >> ai;

    vector<int> acc(n);
    acc[0] = a[0];
    for (int i = 1; i < n; ++i)
        acc[i] = acc[i-1] + a[i];

    int result = numeric_limits<int>::max();
    sort(acc.begin(), acc.end());
    for (int i = 1; i < n; ++i)
        result = min(result, acc[i]-acc[i-1]);

    for (int i = 0; i < n; ++i)
        result = min(result, abs(a[i]));

    cout << result << endl;
}
