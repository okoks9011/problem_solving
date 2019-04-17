#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> s(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> d[i];

    vector<int> start(n);
    for (int i = 0; i < n; ++i) {
        start[i] = s[i];
        if (start[i] >= t)
            continue;

        int diff = t - s[i];
        start[i] += (diff/d[i]) * d[i];
        if (diff % d[i])
            start[i] += d[i];
    }
    cout << min_element(start.begin(), start.end()) - start.begin() + 1 << endl;
}
