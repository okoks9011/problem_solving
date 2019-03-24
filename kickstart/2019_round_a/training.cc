#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int CalTrain(int score, vector<int>& cnt, int p) {
    int result = 0;
    int cur = score;
    while (p > 0 && cur > 0) {
        int need = min(p, cnt[cur]);
        result += (score-cur) * need;
        p -= need;
        --cur;
    }

    if (p > 0)
        return numeric_limits<int>::max();
    else
        return result;
}

int Solve() {
    int n, p;
    cin >> n >> p;

    vector<int> cnt(10001);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        ++cnt[tmp];
    }

    int result = numeric_limits<int>::max();
    for (int i = 1; i <= 10000; ++i) {
        if (cnt[i])
            result = min(result, CalTrain(i, cnt, p));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        auto s = Solve();
        cout << "Case #" << i+1 << ": " << s << endl;
    }
}
