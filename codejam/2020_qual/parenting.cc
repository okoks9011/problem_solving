#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> act(n);
    for (int i = 0; i < n; ++i) {
        auto& t = act[i];
        cin >> get<0>(t) >> get<1>(t);
        get<2>(t) = i;
    }

    sort(act.begin(), act.end());

    string result(n, ' ');
    int c_last = 0;
    int j_last = 0;
    for (auto& t : act) {
        if (c_last <= get<0>(t)) {
            result[get<2>(t)] = 'C';
            c_last = get<1>(t);
        } else if (j_last <= get<0>(t)) {
            result[get<2>(t)] = 'J';
            j_last = get<1>(t);
        } else {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    cout << result;
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
