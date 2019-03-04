#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int CalMinPush(int i, int acc, vector<int>* clocks_ptr, const vector<vector<int>>& sw) {
    auto& clocks = *clocks_ptr;
    if (i == sw.size()) {
        if (all_of(clocks.begin(), clocks.end(), [](int v){return (v%12) == 0;}))
            return acc;
        else
            return numeric_limits<int>::max();
    }

    int result = numeric_limits<int>::max();
    for (int j = 0; j < 4; ++j) {
        result = min(result, CalMinPush(i+1, acc+j, clocks_ptr, sw));
        for (auto& t : sw[i]) {
            clocks[t] += 3;
            clocks[t] %= 12;
        }
    }
    return result;
}

void Solve() {
    vector<int> clocks(16);
    for (auto& clock : clocks)
        cin >> clock;

    vector<vector<int>> sw{
        {0, 1, 2},
        {3, 7, 9, 11},
        {4, 10, 14, 15},
        {0, 4, 5, 6, 7},
        {6, 7, 8, 10, 12},
        {0, 2, 14, 15},
        {3, 14, 15},
        {4, 5, 7, 14, 15},
        {1, 2, 3, 4, 5},
        {3, 4, 5, 9, 13}
    };

    int result =  CalMinPush(0, 0, &clocks, sw);
    if (result == numeric_limits<int>::max())
        cout << -1;
    else
        cout << result;
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
