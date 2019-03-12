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

    vector<int> strong(m, -1);
    for (int i = 0; i < n; ++i) {
        int si;
        cin >> si;
        --si;
        if (strong[si] == -1 || p[strong[si]] < p[i])
            strong[si] = i;
    }

    int result = 0;
    for (int i = 0; i < k; ++i) {
        int ci;
        cin >> ci;
        --ci;
        if (find(strong.begin(), strong.end(), ci) == strong.end())
            ++result;
    }

    cout << result << endl;
}
