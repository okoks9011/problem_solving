#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int target = n / 3;
    deque<deque<int>> buf(3, deque<int>());

    for (int i = 0; i < n; ++i) {
        char tmp_c;
        cin >> tmp_c;
        int num = tmp_c - '0';

        buf[num].emplace_back(i);
    }

    while (buf[0].size() > target) {
        if (buf[2].size() < target) {
            buf[2].emplace_back(buf[0].back());
            buf[0].pop_back();
        } else if (buf[1].size() < target) {
            buf[1].emplace_back(buf[0].back());
            buf[0].pop_back();
        } else {
            // Impossible, Error
            return 1;
        }
    }

    while (buf[1].size() > target) {
        if (buf[0].size() < target) {
            buf[0].emplace_back(buf[1].front());
            buf[1].pop_front();
        } else if (buf[2].size() < target) {
            buf[2].emplace_back(buf[1].back());
            buf[1].pop_back();
        } else {
            // impossible, error
            return 1;
        }
    }

    while (buf[2].size() > target) {
        if (buf[0].size() < target) {
            buf[0].emplace_back(buf[2].front());
            buf[2].pop_front();
        } else if (buf[1].size() < target) {
            buf[1].emplace_back(buf[2].front());
            buf[2].pop_front();
        } else {
            // Impossible, Error
            return 1;
        }
    }

    deque<pair<int, int>> result;
    for (int num = 0; num < buf.size(); ++num) {
        for (auto& i : buf[num]) {
            result.emplace_back(i, num);
        }
    }
    sort(result.begin(), result.end());

    for (auto& p : result)
        cout << p.second;
    cout << endl;
}
