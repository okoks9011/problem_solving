#include <iostream>
#include <deque>

using namespace std;

void Solve() {
    int k, n;
    cin >> k >> n;

    unsigned int seq = 1983;
    int acc = 0;
    int result = 0;
    deque<int> q;
    int i = 0;
    while (i < n) {
        while (i < n && acc <= k) {
            int cur = seq % 10000 + 1;
            seq = seq * 214013 + 2531011;
            ++i;
            q.emplace_back(cur);
            acc += cur;
            if (acc == k)
                ++result;
        }

        while (!q.empty() && k <= acc) {
            acc -= q.front();
            q.pop_front();
            if (acc == k)
                ++result;
        }
    }

    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
