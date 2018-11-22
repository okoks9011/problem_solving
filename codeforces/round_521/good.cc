#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::unordered_set;

using std::max;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    long long sum = 0;
    int max_v = 0;
    for (auto& vi : v) {
        sum += vi;
        max_v = max(max_v, vi);
    }

    int max_cnt = 0;
    for (auto& vi : v) {
        if (vi == max_v)
            ++max_cnt;
    }

    unordered_set<int> s;
    long long nice_v = sum - max_v * 2;
    if (max_cnt != 1 || nice_v != max_v) {
        for (int i = 0; i < n; ++i) {
            if (v[i] == nice_v)
                s.emplace(i+1);
        }
    }

    bool max_nice = false;
    if ((sum - max_v) % 2 == 0) {
        long long new_max = (sum - max_v) / 2;
        if (max_cnt != 1 || new_max != max_v) {
            for (auto& vi : v) {
                if (vi == new_max) {
                    max_nice = true;
                    break;
                }
            }
        }
    }

    if (max_nice) {
        for (int i = 0; i < n; ++i) {
            if (v[i] == max_v)
                s.emplace(i+1);
        }
    }

    cout << s.size() << endl;
    for (auto& si : s) {
        cout << si << " ";
    }
    cout << endl;
}
