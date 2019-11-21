#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    string bob;
    cin >> bob;

    unordered_map<char, int> bob_cnt;
    for (auto& c : bob)
        ++bob_cnt[c];

    int beat = 0;
    beat += min(bob_cnt['S'], a);
    beat += min(bob_cnt['R'], b);
    beat += min(bob_cnt['P'], c);

    if (beat < (n+1) / 2) {
        cout << "NO" << endl;
        return;
    }

    string result(n, ' ');
    for (int i = 0; i < n; ++i) {
        if (bob[i] == 'S' && a > 0) {
            result[i] = 'R';
            --a;
        } else if (bob[i] == 'R' && b > 0) {
            result[i] = 'P';
            --b;
        } else if (bob[i] == 'P' && c > 0) {
            result[i] = 'S';
            --c;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (result[i] != ' ')
            continue;
        if (a > 0) {
            result[i] = 'R';
            --a;
        } else if (b > 0) {
            result[i] = 'P';
            --b;
        } else if (c > 0) {
            result[i] = 'S';
            --c;
        }
    }
    cout << "YES" << endl;
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
