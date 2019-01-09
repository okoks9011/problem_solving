#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << "NO" << endl;
        return 0;
    }

    multiset<int> powers;
    int i = 1;
    while (n) {
        if (n & 1)
            powers.emplace(i);
        n >>= 1;
        i <<= 1;
    }

    if (k < powers.size()) {
        cout << "NO" << endl;
        return 0;
    }

    while (k > powers.size()) {
        auto max_it = --(powers.end());
        int max_power = *max_it;

        powers.erase(max_it);
        powers.emplace(max_power/2);
        powers.emplace(max_power/2);
    }

    cout << "YES" << endl;
    for (auto& p : powers)
        cout << p << " ";
    cout << endl;
}
