#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int aj = *min_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    int result = sum;
    for (auto& ai : a) {
        for (int x = 1; x <= ai; ++x) {
            if (ai % x)
                continue;
            int new_sum = sum - ai - aj + (ai / x) + (aj * x);
            result = min(result, new_sum);
        }
    }

    cout << result << endl;
}
