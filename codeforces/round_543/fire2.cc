#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(n);
    for (auto& pi : p)
        cin >> pi;

    vector<int> s(n);
    for (auto& si : s)
        cin >> si;

    int result = 0;
    for (int i = 0; i < k; ++i) {
        int ci;
        cin >> ci;
        --ci;

        for (int j = 0; j < n; ++j) {
            if (s[j] == s[ci] && p[j] > p[ci]) {
                ++result;
                break;
            }
        }
    }

    cout << result << endl;
}
