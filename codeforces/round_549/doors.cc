#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    vector<int> cnt(2);
    for (auto& ci : c) {
        cin >> ci;
        ++cnt[ci];
    }

    vector<int> cur(2);
    for (int i = 0; i < n; ++i) {
        ++cur[c[i]];
        if (cur[0] == cnt[0] || cur[1] == cnt[1]) {
            cout << i+1 << endl;
            break;
        }
    }
}
