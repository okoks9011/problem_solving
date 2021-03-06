#include <iostream>
#include <vector>
#include <ios>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> freq(n+1);
    int distinct = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        if (freq[t] == 0)
            ++distinct;
        ++freq[t];

        if (distinct == n) {
            for (int j = 1; j <= n; ++j) {
                --freq[j];
                if (freq[j] == 0)
                    --distinct;
            }
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}
