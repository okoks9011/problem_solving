#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    int cur = 0;
    while (p.size() > 2) {
        p.erase(p.begin()+cur);
        cur += k - 1;
        cur %= p.size();
    }
    cout << p[0] << " " << p[1] << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
