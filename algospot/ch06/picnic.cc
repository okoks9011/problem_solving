#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

int CountSeq(int last, int n, unordered_set<int>* history_ptr, const vector<deque<bool>>& f) {
    auto& history = *history_ptr;
    if (n == history.size())
        return 1;

    int result = 0;
    for (int i = last+1; i < n; ++i) {
        if (history.find(i) != history.end())
            continue;

        history.emplace(i);
        for (int j = i+1; j < n; ++j) {
            if (history.find(j) != history.end())
                continue;
            if (!f[i][j] && !f[i][j])
                continue;

            history.emplace(j);
            result += CountSeq(i, n, history_ptr, f);
            history.erase(j);
        }
        history.erase(i);
    }
    return result;
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<deque<bool>> f(n, deque<bool>(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        f[a][b] = true;
        f[b][a] = true;
    }

    unordered_set<int> history;
    cout << CountSeq(-1, n, &history, f) << endl;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
        Solve();
}
