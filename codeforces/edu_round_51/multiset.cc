#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

using std::unordered_map;

using std::unordered_set;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    unordered_map<int, int> counter;
    for (auto& si : s) {
        ++counter[si];
    }

    int one = 0;
    int many = 0;
    for (auto& p : counter) {
        if (p.second == 1)
            ++one;
        if (p.second >= 3) {
            ++many;
        }
    }

    if ((one % 2) && many == 0) {
        cout << "NO" << endl;
        return 0;
    }

    int add_one = one / 2;
    int add_many = 0;
    if (one % 2)
        ++add_many;

    unordered_set<int> a;
    for (auto& p : counter) {
        if (p.second == 1 && add_one) {
            a.emplace(p.first);
            --add_one;
        }
        if (p.second >= 3 && add_many) {
            a.emplace(p.first);
            --add_many;
        }
    }

    cout << "YES" << endl;
    for (auto& si : s) {
        if (a.count(si)) {
            cout << "A";
            a.erase(si);
        } else {
            cout << "B";
        }
    }
    cout << endl;
}
