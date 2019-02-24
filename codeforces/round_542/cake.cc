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
    vector<vector<int>> cnt(n+1);
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        cnt[tmp].emplace_back(i);
    }
    cnt[0] = {0, 0};

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        auto& from = cnt[i-1];
        auto& to = cnt[i];
        int result1 = abs(from[0] - to[0]) + abs(from[1] - to[1]);
        int result2 = abs(from[0] - to[1]) + abs(from[1] - to[0]);
        result += min(result1, result2);
    }
    cout << result << endl;
}
