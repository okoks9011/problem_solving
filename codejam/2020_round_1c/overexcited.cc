#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>
#include <cassert>
#include <cmath>


using namespace std;


void Solve() {
    int x, y;
    cin >> x >> y;
    string path;
    cin >> path;

    unordered_map<char, pair<char, char>> ds{
        {'N', {0, 1}},
        {'E', {1, 0}},
        {'S', {0, -1}},
        {'W', {-1, 0}}
    };

    assert(x != 0 || y != 0);
    int time = 0;
    for (auto& step : path) {
        ++time;
        auto p = ds[step];
        x += p.first;
        y += p.second;
        if (abs(x) + abs(y) <= time) {
            cout << time;
            return;
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
