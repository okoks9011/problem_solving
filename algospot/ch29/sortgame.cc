#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto& vi : v)
        os << vi << ", ";
    return os;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& vi : v)
        cin >> vi;

    vector<int> goal(v);
    sort(goal.begin(), goal.end());

    map<vector<int>, bool> discovered{{v, true}};
    map<vector<int>, int> distance{{v, 0}};
    deque<vector<int>> q{v};
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();

        if (cur == goal) {
            cout << distance[cur] << endl;
            return;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                vector<int> next(cur);
                reverse(next.begin()+i, next.begin()+j);
                if (discovered[next] == true)
                    continue;

                discovered[next] = true;
                distance[next] = distance[cur] + 1;
                q.emplace_back(next);
            }
        }
    }
    assert(false);
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
