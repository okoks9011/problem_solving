#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::min_element;

using std::min;

int main() {
    int n;
    long long s;
    cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    long long sum = 0;
    for (auto& vi : v)
        sum += vi;

    if (s > sum) {
        cout << "-1" << endl;
        return 0;
    }

    long long min_v = *min_element(v.begin(), v.end());
    cout << min((sum-s) / n, min_v) << endl;
}
