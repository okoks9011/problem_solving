#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    deque<int> que;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        que.emplace_back(ai);
    }

    vector<pair<int, int>> history(n);
    history[0] = {que[0], que[1]};
    for (int i = 1; i < n; i++) {
        int a = que.front();
        que.pop_front();
        int b = que.front();
        que.pop_front();
        if (a > b) {
            que.emplace_front(a);
            que.emplace_back(b);
        } else {
            que.emplace_front(b);
            que.emplace_back(a);
        }
        history[i] = {que[0], que[1]};
    }

    for (int i = 0; i < q; i++) {
        long long mi;
        cin >> mi;
        mi--;

        if (mi <= n-1) {
            cout << history[mi].first << " " << history[mi].second << endl;
            continue;
        } else {
            long long second_idx = mi % (n-1);
            cout << que[0] << " " << que[second_idx+1] << endl;
        }
    }
}
