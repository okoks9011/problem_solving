#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

const int kMaxSeq = 500;

void Solve() {
    int a;
    cin >> a;

    vector<char> total(kMaxSeq);
    for (int i = 0; i < a; ++i) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < kMaxSeq; ++j) {
            switch (tmp[j%tmp.size()]) {
                case 'R':
                    total[j] |= 4;
                    break;
                case 'S':
                    total[j] |= 2;
                    break;
                case 'P':
                    total[j] |= 1;
                    break;
                default:
                    assert(false);
                    break;
            }
        }
    }
    if (find(total.begin(), total.end(), 7) != total.end() ||
        (find(total.begin(), total.end(), 1) == total.end() &&
         find(total.begin(), total.end(), 2) == total.end() &&
         find(total.begin(), total.end(), 4) == total.end())) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (int i = 0; i < kMaxSeq; ++i) {
        switch (total[i]) {
            case 2:
            case 6:
                cout << "R";
                break;
            case 1:
            case 3:
                cout << "S";
                break;
            case 4:
            case 5:
                cout << "P";
                break;
            default:
                assert(false);
                break;
        }
    }
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
