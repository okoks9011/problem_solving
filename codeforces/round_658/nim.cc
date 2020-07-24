#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    bool cur_win = true;
    for (int i = n-2; i >= 0; --i) {
        if (a[i] == 1)
            cur_win = !cur_win;
        else
            cur_win = true;
    }

    if (cur_win)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
