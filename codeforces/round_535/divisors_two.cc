#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    auto it = max_element(d.begin(), d.end());
    int a = *it;

    multiset<int> d_mset(d.begin(), d.end());
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            auto hit = d_mset.find(i);
            if (hit != d_mset.end())
                d_mset.erase(hit);
        }

    }

    cout << a << " " << *d_mset.rbegin() << endl;
}
