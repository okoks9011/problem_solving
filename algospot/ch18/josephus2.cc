#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;

    list<int> p(n);
    iota(p.begin(), p.end(), 1);

    auto cur = p.begin();
    while (p.size() > 2) {
        cur = p.erase(cur);
        if (cur == p.end())
            cur = p.begin();

        int step = (k-1) % p.size();
        for (int i = 0; i < step; ++i) {
            ++cur;
            if (cur == p.end())
                cur = p.begin();
        }
    }

    cout << p.front() << " " << p.back() << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
