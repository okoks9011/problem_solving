#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    unordered_set<int> v;
    cerr << "max load factor: " << v.max_load_factor() << endl;
    v.max_load_factor(0.25);
    v.reserve(500);
    bool remove = false;
    for (auto& ai : a) {
        auto it = v.find(ai);
        if (it != v.end()) {
            it = v.find(ai-1);
            if (ai == 0 || remove || it != v.end()) {
                cerr << "Got first condition" << endl;
                if (ai == 0)
                    cerr << "ai is 0" << endl;
                if (remove)
                    cerr << "already removed, can't remove " << ai << endl;
                if (it != v.end())
                    cerr << ai-1 << " exists" << endl;
                cout << "cslnb" << endl;
                return 0;
            } else {
                v.emplace(ai-1);
                cerr << "remove " << ai << endl;
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

    auto stop = high_resolution_clock::now();
    cerr << duration_cast<milliseconds>(stop-start).count() << " ms" << endl;
}
