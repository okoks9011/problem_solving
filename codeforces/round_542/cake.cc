#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 2*n;
    vector<vector<int>> loc(n+1);
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        loc[tmp].emplace_back(i);
    }
    loc[0] = {0, 0};

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        auto& from = loc[i-1];
        auto& to = loc[i];
        result += abs(from[0] - to[0]) + abs(from[1] - to[1]);
    }
    cout << result << endl;
}
