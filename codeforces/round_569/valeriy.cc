#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void Action(deque<int>* a_ptr) {
    auto& a = *a_ptr;
    int a1 = a.front();
    a.pop_front();
    int a2 = a.front();
    a.pop_front();

    if (a1 > a2) {
        a.emplace_front(a1);
        a.emplace_back(a2);
    } else {
        a.emplace_front(a2);
        a.emplace_back(a1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    deque<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    auto it = max_element(a.begin(), a.end());
    int max_idx = it - a.begin();

    vector<pair<int, int>> history;
    for (int i = 0; i < max_idx; ++i) {
        history.emplace_back(a[0], a[1]);
        Action(&a);
    }

    for (int i = 0; i < q; ++i) {
        long long mj;
        cin >> mj;
        --mj;

        if (mj < history.size()) {
            cout << history[mj].first << " " << history[mj].second << endl;
        } else {
            mj -= history.size();
            mj %= (a.size()-1);
            cout << a.front() << " " << a[mj+1] << endl;
        }
    }
}
