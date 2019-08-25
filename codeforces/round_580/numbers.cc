#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> total(401);
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++total[ai];
    }

    int m;
    cin >> m;

    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
        ++total[bi];
    }

    for (auto& ai : a) {
        for (auto& bi : b) {
            if (total[ai+bi] == 0) {
                cout << ai << " " << bi << endl;
                return 0;
            }
        }
    }
    assert(false);
}
