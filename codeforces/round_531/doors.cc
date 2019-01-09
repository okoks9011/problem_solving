#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    if (x > y) {
        cout << n << endl;
        return 0;
    }

    int small_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai <= x)
            ++small_cnt;
    }

    cout << (small_cnt+1) / 2 << endl;
}
