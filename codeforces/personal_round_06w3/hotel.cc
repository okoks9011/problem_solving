#include <iostream>
#include <vector>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    int pad = ((1000000000 + (n-1)) / n) * n;
    vector<char> visit(n);
    for (int i = 0; i < n; ++i) {
        int tmp = a[i] + i;
        if (tmp < 0)
            tmp += pad;
        visit[tmp % n] = true;
    }

    for (auto& vi : visit) {
        if (!vi) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
