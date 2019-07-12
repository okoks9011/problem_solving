#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<char, int>> c(3);
    for (int i = 0; i < 3; ++i)
        cin >> c[i].second >> c[i].first;
    sort(c.begin(), c.end());

    if (c[0] == c[1] && c[1] == c[2]) {
        cout << 0 << endl;
        return 0;
    }
    if (c[0].first == c[1].first && c[1].first == c[2].first) {
        if (c[2].second-c[1].second == 1 && c[1].second-c[0].second == 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (c[0] == c[1] || c[1] == c[2]) {
        cout << 1 << endl;
        return 0;
    }
    if (c[1].first == c[0].first) {
        int diff = c[1].second-c[0].second;
        if (diff == 1 || diff == 2) {
            cout << 1 << endl;
            return 0;
        }
    }
    if (c[2].first == c[1].first) {
        int diff = c[2].second-c[1].second;
        if (diff == 1 || diff == 2) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 2 << endl;
}
