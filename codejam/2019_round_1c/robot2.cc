#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int kMaxSeq = 500;

const char kR = 4;
const char kS = 2;
const char kP = 1;

void Solve() {
    int a;
    cin >> a;

    vector<string> robots(a);
    for (int i = 0; i < a; ++i)
        cin >> robots[i];

    vector<char> live(a, true);
    unordered_map<char, char> convert{{'R', kR}, {'S', kS}, {'P', kP}};
    unordered_map<char, char> win_move{
        {kR|kS, 'R'}, {kS, 'R'},
        {kS|kP, 'S'}, {kP, 'S'},
        {kP|kR, 'P'}, {kR, 'P'}
    };
    string result;
    for (int i = 0; i < kMaxSeq; ++i) {
        char total = 0;
        for (int j = 0; j < a; ++j) {
            if (!live[j])
                continue;
            auto other_move = robots[j][i%robots[j].size()];
            total |= convert[other_move];
        }
        if (total == (kR|kS|kP)) {
            cout << "IMPOSSIBLE";
            return;
        }
        auto my_move = win_move[total];
        result += win_move[total];
        for (int j = 0; j < a; ++j) {
            if (!live[j])
                continue;
            auto other_move = robots[j][i%robots[j].size()];
            if (other_move != my_move)
                live[j] = false;
        }
        if (none_of(live.begin(), live.end(), [](char other){ return other; })) {
            cout << result;
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i+1 << ": ";
        Solve();
        cout << endl;
    }
}
