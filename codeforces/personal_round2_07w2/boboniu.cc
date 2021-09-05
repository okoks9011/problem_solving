#include <iostream>
#include <vector>
#include <cassert>


using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto& ai : a)
        cin >> ai;
    for (auto& bi : b)
        cin >> bi;

    vector<char> cur(512);
    vector<char> pre(512);
    pre[0] = true;
    for (auto& ai : a) {
        for (auto& bi : b) {
            int t = ai & bi;
            for (int j = 0; j < 512; j++) {
                if (!pre[j])
                    continue;
                cur[j | t] = true;
            }
        }
        pre = cur;
        cur = vector<char>(512);
    }
    for (int i = 0; i < 512; ++i) {
        if (pre[i]) {
            cout << i << endl;
            return 0;
        }
    }
    assert(false);
}
