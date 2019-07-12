#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_set<int> v;
    bool remove = false;
    for (auto& ai : a) {
        auto it = v.find(ai);
        if (it != v.end()) {
            if (ai == 0 || remove) {
                cout << "cslnb" << endl;
                return 0;
            } else {
                v.emplace(ai-1);
                remove = true;
            }
        } else {
            v.emplace(ai);
        }
    }

    long long total = 0;
    for (auto& ai : a)
        total += ai;

    long long target = 1LL * (n-1) * n / 2;
    if ((total-target) % 2)
        cout << "sjfnb" << endl;
    else
        cout << "cslnb" << endl;
}
