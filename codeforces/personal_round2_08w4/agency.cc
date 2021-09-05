#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

const int kMod = 1000000007;


vector<vector<int>> comb;

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    if (k == n) {
        cout << 1 << endl;
        return;
    }
    unordered_map<int, int> cnt;
    for (auto& ai : a)
        cnt[ai]++;

    int remain = 0;
    sort(a.begin(), a.end());
    for (int i = n-k-1; i >= 0; i--) {
        if (a[n-k] == a[i])
            remain++;
        else
            break;
    }

    int total = cnt[a[n-k]];
    cout << comb[total][total-remain] << endl;
}


int main() {
    int t;
    cin >> t;

    comb = vector<vector<int>>(1001, vector<int>(1001));
    comb[0][0] = 1;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j <= i; j++) {
            comb[i+1][j] += comb[i][j];
            comb[i+1][j] %= kMod;
            comb[i+1][j+1] += comb[i][j];
            comb[i+1][j+1] %= kMod;
        }
    }

    for (int i = 0; i < t; i++)
        Solve();
}
