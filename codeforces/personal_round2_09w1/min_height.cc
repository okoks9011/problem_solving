#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int level = 1;
    int prev_cnt = 1;
    int cur_cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) {
            cur_cnt++;
            continue;
        }

        if (prev_cnt <= 1) {
            level++;
            prev_cnt = cur_cnt;
            cur_cnt = 1;
        } else {
            prev_cnt--;
            cur_cnt++;
        }
    }
    cout << level << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
