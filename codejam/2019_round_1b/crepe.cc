#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

void Solve() {
    int p, q;
    cin >> p >> q;

    vector<int> prob_x(q+1);
    vector<int> prob_y(q+1);
    for (int i = 0; i < p; ++i) {
        int cur_x, cur_y;
        cin >> cur_x >> cur_y;
        char d;
        cin >> d;
        switch (d) {
            case 'N':
                for (int j = cur_y+1; j <= q; ++j)
                    ++prob_y[j];
                break;
            case 'E':
                for (int j = cur_x+1; j <= q; ++j)
                    ++prob_x[j];
                break;
            case 'S':
                for (int j = cur_y-1; j >= 0; --j)
                    ++prob_y[j];
                break;
            case 'W':
                for (int j = cur_x-1; j >= 0; --j)
                    ++prob_x[j];
                break;
            default:
                assert(false);
        }
    }
    int x = max_element(prob_x.begin(), prob_x.end()) - prob_x.begin();
    int y = max_element(prob_y.begin(), prob_y.end()) - prob_y.begin();
    cout << x << " " << y;
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
