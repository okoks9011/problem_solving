#include <iostream>
#include <vector>
#include <unordered_set>
#include <ios>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> freq(n+1);
    unordered_set<int> ready;
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        ++freq[t];
        ready.emplace(t);

        if (ready.size() == n) {
            for (int j = 1; j <= n; ++j) {
                --freq[j];
                if (freq[j] == 0)
                    ready.erase(j);
            }
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}
