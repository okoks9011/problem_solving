#include <iostream>
#include <vector>
#include <numeric>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> cnt(n+1);
    for (auto& ai : a) {
        cin >> ai;
        cnt[ai]++;
    }

    for (int i = 0; i < n; i++) {
        int cur = a[i];
        for (int j = i+1; j < n; j++) {
            cur += a[j];
            if (cur > n)
                break;

            cnt[cur] = 0;
        }
    }

    int remain = accumulate(cnt.begin(), cnt.end(), 0);
    cout << n - remain << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
