#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::numeric_limits;

using std::min;

using std::abs;

int main() {
    int n;
    cin >> n;

    vector<int> people(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> people[i];

    int min_e = numeric_limits<int>::max();
    for (int x = 1; x <= 100; ++x) {
        int cur_e = 0;
        for (int i = 1; i <= n; ++i) {
            int e = abs(x-i) + abs(i-1) + abs(1-x);
            cur_e += 2 * e * people[i];
        }
        min_e = min(min_e, cur_e);
    }

    cout << min_e << endl;
}
