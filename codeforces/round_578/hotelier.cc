#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> rooms(10);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if (isdigit(c)) {
            rooms[c-'0'] = 0;
        } else {
            int next_idx = -1;
            if (c == 'L') {
                next_idx = find(rooms.begin(), rooms.end(), 0) - rooms.begin();
            } else if (c == 'R') {
                int rev_idx = find(rooms.rbegin(), rooms.rend(), 0) - rooms.rbegin();
                next_idx = 9 - rev_idx;
            } else {
                assert(false);
            }
            rooms[next_idx] = 1;
        }
    }

    for (auto& ri : rooms)
        cout << ri;
    cout << endl;
}
