#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>

using std::ostream;
using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::vector;

using std::pair;
using std::make_pair;

using std::abs;

bool Reachable(int n, pair<int, int> source, pair<int, int> dest) {
    long long dx = abs(dest.first - source.first);
    long long dy = abs(dest.second - source.second);
    auto d = dx + dy;
    if (d > n)
        return false;
    return (n % 2) == (d % 2);
}

bool ReachableWithLength(const vector<pair<int, int>>& seq, pair<int, int> dest, int n) {
    if (seq.size() <= n)
        return true;

    auto pos = make_pair(0, 0);
    for (int i = n; i < seq.size(); ++i) {
        pos.first += seq[i].first;
        pos.second += seq[i].second;
    }

    auto remove_it = seq.begin() + n;
    auto add_it = seq.begin();
    while (true) {
        if (Reachable(n, pos, dest))
            return true;

        if (remove_it == seq.end())
            break;
        pos.first += add_it->first;
        pos.second += add_it->second;
        pos.first -= remove_it->first;
        pos.second -= remove_it->second;
        ++add_it;
        ++remove_it;
    }

    return false;
}

ostream& operator<<(ostream& os, const pair<int, int>& p) {
    os << "(" << p.first << ", " << p.second << ") ";
    return os;
}

int main() {
    int n;
    cin >> n;

    string seq_str;
    cin >> seq_str;

    vector<pair<int, int>> seq(n);
    for (int i = 0; i < n; ++i) {
        auto c = seq_str[i];
        switch(c) {
            case 'U':
                seq[i] = make_pair(0, 1);
                break;
            case 'D':
                seq[i] = make_pair(0, -1);
                break;
            case 'L':
                seq[i] = make_pair(-1, 0);
                break;
            case 'R':
                seq[i] = make_pair(1, 0);
                break;
        }
    }

    int x, y;
    cin >> x >> y;

    if (!Reachable(n, {0, 0}, {x, y})) {
        cout << "-1" << endl;
        return 0;
    }

    int left = 0;
    int right = n;
    int result = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ReachableWithLength(seq, {x, y}, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << result << endl;
}
