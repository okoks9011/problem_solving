#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <numeric>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& vi : v)
        cout << vi << ", ";
    return os;
}

void Prepare(int n, map<vector<int>, int>* distance_ptr) {
    auto& distance = *distance_ptr;

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    deque<vector<int>> q{v};
    distance[v] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                vector<int> next(cur);
                reverse(next.begin()+i, next.begin()+j);

                auto it = distance.find(next);
                if (it != distance.end())
                    continue;

                distance[next] = distance[cur] + 1;
                q.emplace_back(next);
            }
        }
    }
}

void Solve(map<vector<int>, int>& distance) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto& vi : v)
        cin >> vi;

    vector<int> normal;
    for (int i = 0; i < n; ++i) {
        int smaller = count_if(v.begin(), v.end(), [&](int vj){ return vj < v[i]; });
        normal.emplace_back(smaller);
    }

    cout << distance[normal] << endl;
}

int main() {
    int c;
    cin >> c;

    map<vector<int>, int> distance;
    for (int i = 1; i <= 8; ++i)
        Prepare(i, &distance);

    for (int i = 0; i < c; ++i)
        Solve(distance);
}
