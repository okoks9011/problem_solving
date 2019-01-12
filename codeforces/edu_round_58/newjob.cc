#include <iostream>
#include <algorithm>
#include <ios>

using std::cout;
using std::endl;
using std::cin;

using std::max;

using std::swap;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_s = 0;
    int max_l = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        int s, l;
        cin >> c >> s >> l;
        if (s > l)
            swap(s, l);

        if (c == '+') {
            max_s = max(max_s, s);
            max_l = max(max_l, l);
        } else if (c == '?') {
            if (max_s <= s && max_l <= l)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
