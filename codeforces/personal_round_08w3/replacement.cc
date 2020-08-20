#include <iostream>
#include <set>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> loc;
    char prev = 'a';
    int score = 0;
    for (int i = 1; i <= n; ++i) {
        char cur;
        cin >> cur;
        if (cur == '.') {
            loc.emplace(i);
            if (prev == '.')
                ++score;
        }
        prev = cur;
    }

    for (int i = 0; i < m; ++i) {
        int x;
        char c;
        cin >> x >> c;

        auto it = loc.find(x);
        if (c == '.') {
            if (it != loc.end()) {
                cout << score << endl;
                continue;
            }
            loc.emplace(x);
        } else {
            if (it == loc.end()) {
                cout << score << endl;
                continue;
            }
            loc.erase(x);
        }

        auto next_it = loc.upper_bound(x);
        int next;
        if (next_it != loc.end())
            next = *next_it;
        else
            next = n + 2;

        auto prev_it = loc.lower_bound(x);
        int prev;
        if (prev_it != loc.begin()) {
            --prev_it;
            prev = *prev_it;
        } else {
            prev = -1;
        }

        if (c == '.') {
            if (next - x == 1)
                ++score;
            if (x - prev == 1)
                ++score;
        } else {
            if (next - x == 1)
                --score;
            if (x - prev == 1)
                --score;
        }
        cout << score << endl;
    }
}
