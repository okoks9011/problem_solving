#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::reverse;

using std::abs;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    char tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp == '(')
            b[i] = 1;
        else if (tmp == ')')
            b[i] = -1;
    }

    int lp_cnt = 0;
    int rp_cnt = 0;
    for (auto& c : b) {
        if (c == 1)
            ++lp_cnt;
        else if (c == -1)
            ++rp_cnt;
    }

    if (abs(lp_cnt-rp_cnt) != 2) {
        cout << "0" << endl;
        return 0;
    } else if (lp_cnt-rp_cnt == 2) {
        for (auto& c : b)
            c *= -1;
        reverse(b.begin(), b.end());
    }

    int acc = 0;
    for (auto& c : b) {
        acc += c;
        if (acc < -2) {
            cout << "0" << endl;
            return 0;
        }
    }

    int result = 0;
    acc = 0;
    for (auto& c : b) {
        acc += c;
        if (c == -1)
            result += 1;
        if (acc <= -1)
            break;
    }
    cout << result << endl;
}
