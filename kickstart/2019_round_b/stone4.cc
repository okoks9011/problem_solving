#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stone {
    int s = 0;
    int e = 0;
    int l = 0;

    Stone() = default;
    Stone(int is, int ie, int il) : s(is), e(ie), l(il) {}

    bool operator<(const Stone& other) const {
        return l < other.l;
    }
};

int CalMaxEnergy(vector<vector<int>>* dp_ptr, int i, int j,
                 const vector<Stone>& stones) {
    if (i >= stones.size())
        return 0;
    auto& dp = *dp_ptr;
    auto& result = dp[i][j];
    if (result != -1)
        return result;

    int lose = stones[i].s * stones[i].l * j;
    result = max(CalMaxEnergy(dp_ptr, i+1, j, stones),
                 CalMaxEnergy(dp_ptr, i+1, j+1, stones)+max(0, stones[i].e-lose));
    return result;
}

int Solve() {
    int n;
    cin >> n;

    vector<Stone> stones;
    for (int i = 0; i < n; ++i) {
        int si, ei, li;
        cin >> si >> ei >> li;
        stones.emplace_back(si, ei, li);
    }

    sort(stones.rbegin(), stones.rend());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return CalMaxEnergy(&dp, 0, 0, stones);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
