#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <numeric>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int result = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> b_tmp(b);
        for (int j = i; j < n; j += k)
            b_tmp[j] = 0;

        int s = abs(accumulate(b_tmp.begin(), b_tmp.end(), 0));
        result = max(result, s);
    }
    cout << result << endl;
}
