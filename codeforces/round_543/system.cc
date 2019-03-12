#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Worker {
    int cur = 0;
    int total = 0;
    bool active = false;
    bool interest = false;
};

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> q(n);
    for (auto& qi : q)
        cin >> qi;

    vector<Worker> pool(k);
    int m = 0;
    int result = 0;
    while (!q.empty() || any_of(pool.begin(), pool.end(), [](Worker& w){return w.active;})) {
        for (auto& w : pool) {
            if (w.active || q.empty())
                continue;
            w.total = q.front();
            q.pop_front();

            w.cur = 1;
            w.active = true;
        }

        int d = static_cast<int>((100.0*m/n)+0.5);
        for (auto& w : pool) {
            if (w.active && w.cur == d)
                w.interest = true;
        }

        for (auto& w : pool) {
            if (!w.active)
                continue;
            if (w.cur < w.total) {
                ++w.cur;
            } else {
                if (w.interest)
                    ++result;
                w.active = false;
                w.interest = false;
                ++m;
            }
        }
    }

    cout << result << endl;
}
